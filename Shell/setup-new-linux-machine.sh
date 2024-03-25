#!/bin/bash

prompt_for_user_input=true
apps_list=(vim git code 'dotnet-sdk-8.0' 'aspnetcore-runtime-8.0' copyq 'signal-desktop')

install_code () {
  sudo apt-get install wget gpg
  wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
  sudo install -D -o root -g root -m 644 packages.microsoft.gpg /etc/apt/keyrings/packages.microsoft.gpg
  sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/keyrings/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'
  rm -f packages.microsoft.gpg
  
  sudo apt install apt-transport-https
  sudo apt update
  sudo apt install code # or code-insiders
}

install_signal () {
  # 1. Install our official public software signing key:
  wget -O- https://updates.signal.org/desktop/apt/keys.asc | gpg --dearmor > signal-desktop-keyring.gpg
  cat signal-desktop-keyring.gpg | sudo tee /usr/share/keyrings/signal-desktop-keyring.gpg > /dev/null

  # 2. Add our repository to your list of repositories:
  echo 'deb [arch=amd64 signed-by=/usr/share/keyrings/signal-desktop-keyring.gpg] https://updates.signal.org/desktop/apt xenial main' |\
    sudo tee /etc/apt/sources.list.d/signal-xenial.list

  # 3. Update your package database and install Signal:
  sudo apt update && sudo apt install signal-desktop
}

check_app () {
  case "$1" in

    dotnet-sdk-*)
      dotnet --list-sdks | grep "${1##*-}"
    ;;

    *netcore-runtime-*)
      dotnet --list-runtimes | grep "${1##*-}"
    ;;

    *)
      which "$1"
    ;;

  esac
}

setup_app () {
  case "$1" in 

    git)
      git config --global core.autocrlf input
      git config --global core.editor "vim"
      if $prompt_for_user_input
      then
        read -p "author name for git: " name_git
        git config --global user.name "$name_git"
        read -p "author email for git: " email_git
        git config --global user.email "$email_git"
      fi
    ;;

    *)
      echo "noop"
    ;;

  esac
}

install_app () {
  case "$1" in
    
    code)
      install_code
    ;;

    signal-desktop)
      install_signal
    ;;

    *)
      sudo apt install "$1"
    ;;

  esac  

  setup_app
}

install_apps () {
  for app in "${apps_list[@]}"
  do
    if check_app "$app"
    then
      echo "$app installed already."
    else
      echo "installing $app ..."
      install_app "$app"
    fi
  done  
}

install_apps

# TODO: Clone P_S repo, copy out bash settings, .vimrc etc.
  # git remote set-url origin ssh://git@github.com/<username>/<repo>.git
  # ssh-keygen -t ed25519 -C "<email>"
  # eval "$(ssh-agent -s)"
  # ssh-add ~/.ssh/<file>
  # cat ~/.ssh/<file>.pub

# TODO: Don't ask for sudo password too often.
  # sudo visudo

# TODO: Change locale for date-time.

# TODO: Mouse scroll direction (down scrolls down)
  # https://askubuntu.com/questions/819662/how-to-invert-touchpad-scrolling-on-ubuntu-16-04
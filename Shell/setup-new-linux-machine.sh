#!/bin/bash

apps_list=(git vim code 'dotnet-sdk-8.0' 'aspnetcore-runtime-8.0' copyq)

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
  # TODO: add setup for things like crlf, author and ssh keys for git.
  # git config --global core.autocrlf input
  # git config --global user.name "<name>"
  # git config --global user.email "<email>"
  # git remote set-url origin ssh://git@github.com/<username>/<repo>.git
  # ssh-keygen -t ed25519 -C "<email>"
  # eval "$(ssh-agent -s)"
  # ssh-add ~/.ssh/<file>
  # cat ~/.ssh/<file>.pub
  echo "noop"
}

install_app () {
  case "$1" in
    
    code)
      install_code
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


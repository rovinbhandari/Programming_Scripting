#!/bin/bash

prompt_for_user_input=true
apps_list=(vim git code 'dotnet-sdk-8.0' 'aspnetcore-runtime-8.0' copyq 'signal-desktop')
dock_apps=(firefox Nautilus Terminal code) # to be used for searching for appropriate .desktop files in /usr/share/applcations
dock_apps_initial_string="['firefox_firefox.desktop', 'org.gnome.Nautilus.desktop', 'org.gnome.Terminal.desktop', 'code.desktop']" # static string for simpler implementation in the beginning

# Installation Functions
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

      vim)
        if ! test -f ~/.vimrc
        then
          wget "https://raw.githubusercontent.com/rovinbhandari/Programming_Scripting/master/configs_settings/_vimrc"
          mv _vimrc ~/.vimrc
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
    func_input=$1[@]
    apps=("${!func_input}")
    for app in "${apps[@]}"
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

# Customization Functions
  customize_dock () {
    current_favourites=$(dconf read /org/gnome/shell/favorite-apps)

    # check for indications of whether we've set the favourite apps before
    # by checking if the order of core apps is "correct".
    # TODO: this should not be a literal string comparison to avoid discrepancies
    # between files like firefox_firefox.desktop and firefox.desktop
    if ! [[ ${current_favourites: 0:${#dock_apps_initial_string}-1} == ${1: 0:-1} ]]
    then
      echo "Resetting favourite apps on dock to: $1"
      dconf write /org/gnome/shell/favorite-apps "$1"
    # TODO: otherwise, extract apps from $dock_apps and amend favourites to include
    # existing favourites plus those in $dock_apps
    # else
    fi
  }

main () {
  # FUNCTIONAL
    # Install useful apps
    install_apps apps_list

    # TODO: Add docker to apps_list
    # TODO: Clone P_S repo, copy out bash settings, .vimrc etc.
      # git remote set-url origin ssh://git@github.com/<username>/<repo>.git
      # ssh-keygen -t ed25519 -C "<email>"
      # eval "$(ssh-agent -s)"
      # ssh-add ~/.ssh/<file>
      # cat ~/.ssh/<file>.pub

  # PRODUCTIVITY
    # Pin Terminal and Code to Taskbar (Dock)
      # https://askubuntu.com/questions/1026528/adding-custom-programs-to-favourites-of-ubuntu-dock#comment2034004_1026532
    customize_dock "$dock_apps_initial_string" $dock_apps

    # TODO: Mouse scroll direction (down scrolls down)
      # https://askubuntu.com/questions/819662/how-to-invert-touchpad-scrolling-on-ubuntu-16-04
    # TODO: Don't ask for sudo password too often.
      # sudo visudo
    # TODO: Add extra keyboard layouts
    # TODO: Set timezone

  # VISUAL/COSMETIC
    # TODO: Change to dark theme
    # TODO: Change locale (Formats) for date-time to UK.
}

# Make it possible to import script or run standalone
if [ "${1}" != "--source-only" ]
then
    main "${@}"
fi
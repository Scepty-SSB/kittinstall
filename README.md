# Kittinstall: The package manager manager
KittInstall is a tool for installing packages from any manager that exists on the system. It is currently neither finished nor usable.

# How it works
Kittinstall searches for executables in your $PATH that match a list of package managers. It will then automatically set any managers it finds to be enabled. Use `kittinstall --list` to see a list of enabled package managers. If you want to specifically exclude one package manager from Kittinstall, use `kittinstall --inclusion-toggle foo` where `foo` is the name of the package manager to exclude. Use the same command again to re-enable the manager.
If a package manager on your system is not automatically detected, use `kittinstall --manual-add foo s i b` to add it manually, where `foo` is the name of the manager, `s` is the argument used to search for packages, `i` is the argument used to install packages, and `b` is whether installation from the manager requires sudo priveliges (either `true` or `false`). For example, to manually add flatpak:
`kittinstall --manual-add flatpak search install false`
Or for pacman:
`kittinstall --manual-add yay -s -S false`

# Important note for Arch users
If yay (or another AUR helper that includes packages from pacman) is installed on your system, Kittinstall will disable pacman by defualt. This is to decrease clutter in search results. `kittinstall --inclusion-toggle pacman` will re-enable it.
{
  pkgs ? import <nixpkgs> { },
}:

with pkgs;
mkShell {
  name = "zathura-png";
  buildInputs = [
    meson
    ninja
    pkg-config
    zathura
    girara
  ];
}

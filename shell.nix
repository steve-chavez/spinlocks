let
  nixpkgs = builtins.fetchTarball {
    name = "2020-12-22";
    url = "https://github.com/NixOS/nixpkgs/archive/2a058487cb7a50e7650f1657ee0151a19c59ec3b.tar.gz";
    sha256 = "1h8c0mk6jlxdmjqch6ckj30pax3hqh6kwjlvp2021x3z4pdzrn9p";
  };
in with import nixpkgs {};
mkShell {
  buildInputs =
  let
    benchScript = writeShellScriptBin "spinlock-bench" ''
      time $1
      time $1 2
      time $1 4
      time $1 8
    '';
    statScript = writeShellScriptBin "spinlock-stat" ''
      perf stat -d $1 8
    '';
  in
  [
    linuxPackages.perf gcc
    benchScript
    statScript
  ];
  shellHook = ''
  '';
}

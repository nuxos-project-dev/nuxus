# Nuxus, a unix-like kernel compatible with linux for NuxOS project

![License: GPLv2](https://img.shields.io/badge/License-GPLv2-yellow)
![Written in: C & Assembly](https://img.shields.io/badge/Written%20in-C%20&%20Assembly-blue)
![License: BSD 2 Clause](https://img.shields.io/badge/License-BSD%202%20Clause-red)

## Usage

To compile the kernel, run:
```bash
make
```

This will compile kernel for you.
To configure modules, you can change DEFAULTS variable in Makefile

### To compile multi-thread, run
```bash
make -j$(nproc)
```

## License
This project is licensed under GPL-2.0-or-later.
Some parts of project licensed under GPL-2.0-or-later OR BSD-2-Clause.
For commercial licensing or inquiries, feel free to contact me via email: palaomer100@gmail.com

## Credits

This project incorporates components from the following open-source projects:

- **POSIX-UEFI**: Header files and UEFI boot infrastructure wrappers.
  - **Author**: bzt
  - **License**: MIT License
  - **Source**: https://gitlab.com/bztsrc/posix-uefi

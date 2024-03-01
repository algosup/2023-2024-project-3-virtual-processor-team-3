# ALGOSUP - 2023-2024 - Project 3 - Virtual Processor - Team 3

## Team Members
| **Photo** | **Name** | **Role** | **GitHub/LinkedIn** |
|---|---|---|---|
| <img src="./documents/img/thibault.png" width="150" height="150">| MARLIER Thibaud | Project Manager | [GitHub](https://github.com/Biohazardyee) \| [LinkedIn](https://www.linkedin.com/in/thibaud-marlier/) |
| <img src="./documents/img/quentin.png" width="150" height="150"> | CLEMENT Quentin | Program Manager | [GitHub](https://github.com/Quentin-Clement) \| [LinkedIn](https://www.linkedin.com/in/quentin-clément-939110221/) |
| <img src="./documents/img/aurelien.png" width="150" height="150"> | FERNANDEZ Aurélien | Technical Leader | [GitHub](https://github.com/aurelienfernandez) \| [LinkedIn](https://www.linkedin.com/in/aurélien-fernandez-4971201b8/) |
| <img src="./documents/img/malo.png" width="150" height="150"> | ARCHIMBAUD Malo| Software Engineer | [GitHub](https://github.com/Malo-Archimbaud) \| [LinkedIn](https://www.linkedin.com/in/malo-archimbaud-58aa12232/) |
| <img src="./documents/img/mathis.png" width="150" height="150"> | KAKAL Mathis | Software Engineer | [GitHub](https://github.com/mathiskakal) \| [LinkedIn](https://www.linkedin.com/in/mathis-k-a239ba10a/) |
| <img src="./documents/img/arthur.png" width="150" height="150"> | LEMOINE Arthur | Quality Assurance | [GitHub](https://github.com/arthur-lemo1ne) \| [LinkedIn](https://www.linkedin.com/in/arthur-lemoine-4b9782221/) |

## Overview

This project is an ALGOSUP project, driven by the students. This project aims to create a Virtual Processor along with an Assembly language to run instructions on it. Moreover, we have to develop a built-in debugger. All of that, using plain and portable C language (only standard libraries are allowed).




## What Is ALGORISK

ALGORISK is our processor, it stands for ALGOSUP RISK, the risk refers to RISC V from which we got inspired to create our processor.

## What Is ALGORASM

ALGORASM is our assembly language, it stands for ALGORISK  assembly. The files written in ALGORASM are either text files or .gras files, which means gorisk assembly.

Processing a text file written in ALGORASM or a .gras file will create a new file named as the previous one but with the .grml extension.

## How To Install

Firstly, you'll need to install GCC (if not done yet): [Download GCC now](https://gcc.gnu.org) ! \
Follow the instructions to download gcc on the website.

- Then, check out our latest release: [Latest release here](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-3/tags)
- Download the source code. You'll find everything you need, documentation, code, etc... Feel free to familiarize yourself with the files.
- And voila! You're all set for a fresh start with ALGORASM and ALGORISK.

## GitHub Extension

By following the link down below, you'll get redirected to the "necessary" Visual Studio Code Extension for ALGORISK, this is a set of tools for you, from snippets to syntax highlighting. \
You'll find everything you need to code with our Assembly. \
[Link to the extension](https://marketplace.visualstudio.com/items?itemName=ALGORISKTEAM.algorisk-language-support)

## How To Use

To **code in ALGORASM** feel free to check the documentation here: [Instruction Set Manual](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-3/blob/main/documents/Assembly_documentation/ALGORISK_documentation.pdf)

To **use our virtual processor** you can choose between 3 different commands:

```
./main.exe gorasm [your file name].txt
```
Your file should contain ALGORISK assembly, else it may return an error.

This command will assemble the ALGORISK assembly into a .grml file, containing the binary of your program.

```
./main.exe goproc [your file name].grml
```

This command will execute the binary of a .grml file.


```
./main.exe gorisk [your file name].txt
```

This command executes the two previous commands into one.

## License

This project is under the [MIT License](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-3/blob/main/LICENSE)

Copyright (c) 2024 ALGOSUP

![image](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-3/blob/main/documents/Assembly_documentation/img/logo_algosup.png?raw=true)

<div> <a href="./"><img src="../img/functional_specifications/back2.png" width="35px"></a>
</div>

<h1 align="center"> ALGORISK Documentation </h1>

<p align="center">
Created by: Thibaud MARLIER <br> Creation Date: 02/09/2024 <br> Last update: 02/16/2024
</p>

___

<details>

- [Copyright](#copyright)
- [Content](#content)
- [I. Introduction](#i-introduction)
  - [Before you read](#before-you-read)
- [Chapter 1: Overview of the ALGORISK Assembler](#chapter-1-overview-of-the-algorisk-assembler)
  - [Assembler overview](#assembler-overview)
  - [Assembler Directives](#assembler-directives)
- [Chapter 2: Instruction Set](#chapter-2-instruction-set)
  - [General Purpose Instructions](#general-purpose-instructions)
    - [Data Transfer Instructions](#data-transfer-instructions)
    - [Binary Arithmetic Instructions](#binary-arithmetic-instructions)
    - [Logical Instructions](#logical-instructions)
    - [Shift and Rotate Instructions](#shift-and-rotate-instructions)
    - [Bit and Byte Instructions](#bit-and-byte-instructions)
    - [Control Transfer Instructions](#control-transfer-instructions)
    - [String Instructions](#string-instructions)
- [Index](#index)

</details>

___

## Copyright

Copyright (c) 2024 ALGOSUP
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
The software is provided "as is", without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose and noninfringement. In no event shall the authors or copyright holders be liable for any claim, damages or other liability, whether in an action of contract, tort or otherwise, arising from, out of or in connection with the software or the use or other dealings in the software.

___

<div align="center"><img src="https://algosup.com/wp-content/uploads/2022/09/logo-white.png">
</div>

___

## Content

- [Copyright](#copyright)
- [Content](#content)
- [I. Introduction](#i-introduction)
  - [Before you read](#before-you-read)
- [Chapter 1: Overview of the ALGORISK Assembler](#chapter-1-overview-of-the-algorisk-assembler)
  - [Assembler overview](#assembler-overview)
  - [Assembler Directives](#assembler-directives)
- [Chapter 2: Instruction Set](#chapter-2-instruction-set)
  - [General Purpose Instructions](#general-purpose-instructions)
    - [Data Transfer Instructions](#data-transfer-instructions)
    - [Binary Arithmetic Instructions](#binary-arithmetic-instructions)
    - [Logical Instructions](#logical-instructions)
    - [Shift and Rotate Instructions](#shift-and-rotate-instructions)
    - [Bit and Byte Instructions](#bit-and-byte-instructions)
    - [Control Transfer Instructions](#control-transfer-instructions)
    - [String Instructions](#string-instructions)
- [Index](#index)


## I. Introduction

### Before you read

**Who should use this documentation?**

The ALGORISK Assembly documentation is aimed at every user of our Assembler. It will help you throughout your journey of coding with our language and break down all the instructions for a deeper understanding of the ALGORISK language.

## Chapter 1: Overview of the ALGORISK Assembler

### Assembler overview

### Assembler Directives

## Chapter 2: Instruction Set

### General Purpose Instructions

**The general-purpose instructions perform basic data movement, memory addressing,
arithmetic and logical operations, output, and string operations on
integers and pointers.**

In this documentation, you'll find registers which are defined as:

- rd = Destination Register
- r1 = Register number one
- r2 = Register number two

#### Data Transfer Instructions

|ALGORISK instuction|Expanding|Description|Example|
|---|---|---|---|
|**lb**| Load Byte |Loads a signed byte from memory into a register, the address in memory must be specified as an operand| ``` lb rd, address ```|
|**lbu**| Load Byte Unsigned| Loads an unsigned byte from memory into a register, the address in memory must be specified as an operand| ``` lbu rd, address ```|
|**lh**| Load Halfword| Loads a signed halfword from memory into a register, the address in memory must be specified as an operand | ``` lh rd, address ```|
|**lhu**| Load Halfword Unsigned| Loads an unsigned halfword from memory into a register, the address in memory must be specified as an operand | ``` lhu rd, address ```|
|**lw**| Load Word | Loads a word from memory into a register, the address in memory must be specified as an operand | ``` lw rd, address ```|
|**lui**| Load Upper Immediate | Loads an immediate value into the upper 20 bits of a register, the lower 12 bits are set to 0 | ``` lui rd, immediate ```|
|**sb**| Store Byte | Stores the lower 8 bits of a register into memory, the address in memory must be specified as an operand | ``` sb rd, address ```|
|**sh**| Store Halfword | Stores the lower 16 bits of a register into memory, the address in memory must be specified as an operand | ``` sh rd, address ```|
|**sw**| Store Word | Stores the lower 32 bits of a register into memory, the address in memory must be specified as an operand | ``` sw rd, address ```|


#### Binary Arithmetic Instructions

#### Logical Instructions

The logical instructions perform basic logical operations on their operands.

|ALGORISK instuction|Description|Example|
|---|---|---|
|add| Adds the contents of two registers and stores the result in a register| ``` add rd, r1,r2 ```|

#### Shift and Rotate Instructions

#### Bit and Byte Instructions

#### Control Transfer Instructions

auipc

#### String Instructions

## Index

<div align="right"><a href="#copyright"><img src="../img/functional_specifications/back.png" width="35px"></a></div>

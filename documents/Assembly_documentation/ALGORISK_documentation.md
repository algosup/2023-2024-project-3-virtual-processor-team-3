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
    - [Shift Instructions](#shift-instructions)
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
    - [Shift Instructions](#shift-instructions)
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

#### Data Transfer Instructions

#### Binary Arithmetic Instructions

#### Logical Instructions

The logical instructions perform basic logical operations on their operands.

| ALGORISK instuctions |Expanding| Description| Example |
| ---| --- | --- | --- |
| **and** | - |Performs a bitwise AND operation on the values of two registers and stores the result in a register | ```and rd, r1,r2```         |
| **andi** | Add immediate | Performs a bitwise AND operation on the values of a register and an immediate and stores the result in a register | ```andi rd, r1,immediate``` |
| **or** | - |  Performs a bitwise OR operation on the values of two registers and stores the result in a register | ```or rd, r1, r2```         |
| **ori** | Or immediate | Performs a bitwise OR operation on the values of a register and an immediate and stores the result in a register  | ```ori rd, r1, immediate```  |
| **xor** | Exclusive or|Performs a bitwise XOR operation on the values of two registers and stores the result in a register | ```xor rd, r1, r2	```         |
| **xori** | Exclusive or immediate |Performs a bitwise XOR operation on the values of a register and an immediate and stores the result in a register | ```xori rd, r1, immediate ``` |

#### Shift Instructions

| ALGORISK instuctions |Expanding| Description| Example |
| ---| --- | --- | --- |
| **sll** | Shift left logical | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | ```sll rd, r1, r2```         |
| **slli** | Shift Left Logical Immediate | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | ```slli rd, r1, immediate``` |
| **srl** | Shift Right Logical	 | Makes a logical shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | ```srl rd, r1, r2```         |
| **srli** | Shift Right Logical Immediate | Makes a logical shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register | ```srli rd, r1, immediates```  |
| **sra** | Shift Right Arithmetic |Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | ```sra rd, r1, r2```         |
| **xori** | Exclusive or immediate |Performs a bitwise XOR operation on the values of a register and an immediate and stores the result in a register | ```xori rd, r1, immediate ``` |

#### Bit and Byte Instructions

#### Control Transfer Instructions

#### String Instructions

## Index


<div align="right"><a href="#copyright"><img src="../img/functional_specifications/back.png" width="35px"></a></div>

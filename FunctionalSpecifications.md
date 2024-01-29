<div align="left"><a href="https://github.com/algosup/2023-2024-project-3-virtual-processor-team-3"><img src="Documents/Img/FunctionalSpecifications/back2.png" width="35px"></a></div>

<br>

<h1 align="center"> Functional Specifications </h1>

<p align="center"> 
Created by: Quentin CLÉMENT <br> Creation Date: 12/01/2024 <br> Last update: 26/01/2024
</p>

<details>
<summary>

## Table of Contents

</summary>

- [Table of Contents](#table-of-contents)
- [1. Glossary](#1-glossary)
- [2. Introduction](#2-introduction)
  - [2.1 Overview](#21-overview)
  - [2.2 Project Definition](#22-project-definition)
    - [➭ 2.2.1 Vision](#-221-vision)
    - [➭ 2.2.2 Scope](#-222-scope)
    - [➭ 2.2.3 Deliverables](#-223-deliverables)
  - [2.3 Project Organisation](#23-project-organisation)
    - [➭ 2.3.1 Project Representatives](#-231-project-representatives)
    - [➭ 2.3.2 Stakeholders](#-232-stakeholders)
    - [➭ 2.3.3 Project Roles](#-233-project-roles)
    - [➭ 2.3.4 Project Reviewers](#-234-project-reviewers)
  - [2.4 Project Plan](#24-project-plan)
    - [➭ 2.4.1 Retroplanning](#-241-retroplanning)
    - [➭ 2.4.2 Milestones](#-242-milestones)
    - [➭ 2.4.3 Dependencies](#-243-dependencies)
    - [➭ 2.4.4 Resources/Help/Financial plan](#-244-resourceshelpfinancial-plan)
    - [➭ 2.4.5 Assumptions/Constraints](#-245-assumptionsconstraints)
- [3. Virtual Processor Architecture](#3-virtual-processor-architecture)
  - [3.1 Registers](#31-registers)
  - [3.2 ALU](#32-alu)
- [4. Assembly Language](#4-assembly-language)
  - [4.1 Sections](#41-sections)
  - [4.2 Instruction types and binary formats](#42-instruction-types-and-binary-formats)
  - [4.3 Instructions Set Architecture](#43-instructions-set-architecture)
- [5. From ALGORISK assembly to executable](#5-from-algorisk-assembly-to-executable)
  - [5.1 Preprocessor](#51-preprocessor)
  - [5.2 Interpreter](#52-interpreter)
    - [➭ 5.2.1 Instruction error](#-521-instruction-error)
    - [➭ 5.2.2 Operand error](#-522-operand-error)
    - [➭ 5.2.3 Variable declaration error](#-523-variable-declaration-error)
  - [5.3 Assembler](#53-assembler)
  - [5.4 Execution](#54-execution)
    - [➭ 5.4.1 Loader](#-541-loader)
    - [➭ 5.4.2 Execution Unit](#-542-execution-unit)
    - [➭ 5.4.3 Exception handling](#-543-exception-handling)
    - [➭ 5.4.4 System calls](#-544-system-calls)
- [6. Debugger](#6-debugger)
- [7. Plugin](#7-plugin)
    - [➭ 3.5.1 Color highlighting](#-351-color-highlighting)
    - [➭ 3.5.2 Snippets](#-352-snippets)
- [8. Conclusion](#8-conclusion)

</details>

## 1. Glossary

| Term              | Definition | Source/s |
| ----------------- | ---------- | -------- |
| Assembly Language |            |          |
| Virtual Processor |            |          |
| Interpreter       |            |          |
| RISC              |            |          |
| RISC-V            |            |          |


## 2. Introduction

### 2.1 Overview

This project aims to build an original virtual processor and interpreter in plain C language. We have to invent a new assembly including essential instructions to run on this interpreter. 

In short, let's create our perfect processor!

### 2.2 Project Definition

#### ➭ <ins>2.2.1 Vision</ins>

We will create a virtual processor in C named ALGORISK, and an easy to use assembly language to run on it. \
The goal is to make programming and computer science more accessible to everyone. \
We want beginners to learn how a computer works at a low level, without being disgusted with too complex and specific instructions. 

#### ➭ <ins>2.2.2 Scope</ins>

| In Scope |
| -------- |
| Create an optimizesd 32-bit virtual processor with 32 registers |
| Invent an assembly language with an explicit instruction set and a clear syntax |
| Execute programs written in ALGORISK assembly on a ALGORISK virtual processor |
| Transform the program's instructions into machine code before executing it | 
| Be able to debug programs written in ALGORISK assembly |
| Develop exclusively in C without the use of any external library |


| Out of Scope |
|---|
| Implement interrupts |
| Implement multi-threading |
| Implement atomic instructions |


#### ➭ <ins>2.2.3 Deliverables</ins>

| Name                               | Type                | Deadline     | Link                                                         |
| ---------------------------------- | ------------------- | ------------ | ------------------------------------------------------------ |
| Functional Specifications Document | Document (markdown) | 30/01/2024   | [FunctionalSpecifications.md](./FunctionalSpecifications.md) |
| Technical Specifications Document  | Document (markdown) | 09/02/2024   | [Technical-Specifications.md](./technicalSpecifications.md)  |
| Weekly Reports                     | Document (markdown) | Every Friday | [Weekly-Reports/](./weeklyReports/)                          |
| Test Plan                          | Document (markdown) | 16/02/2024   | [Test-Plan.md](./qualityAssurance/Test-Plan.md)              |
| Final Product                      | TODETERMINE         | 23/02/2024   |                                                              |

### 2.3 Project Organisation

#### ➭ <ins>2.3.1 Project Representatives</ins>

| Project Owner   | Represented by...                                |
| --------------- | ------------------------------------------------ |
| **ALGOSUP**     | Represented by Franck JEANNIN                    |
| Thibaud MARLIER | Represented by Quentin CLÉMENT (Program Manager) |

The project sponsors (highlighted in **bold**) are expected to be in charge of:

- Defining the vision and high-level objectives for the project.
- Approving the requirements, timetable, resources and budget (if necessary).
- Authorising the provision of funds/resources (internal or external) (if necessary).
- Approving the functional and technical specifications written by the team.
- Ensuring that major business risks are identified and managed by the team.
- Approving any major changes in scope.
- Received Project Weekly Reports and take action accordingly to resolve issues escalated by the Project Manager.
- Ensuring business/operational support arrangements are put in place.
- Ensuring the participation of a business resource (if required).
- Providing final acceptance of the solution upon project completion.

#### ➭ <ins>2.3.2 Stakeholders</ins>

| Stakeholder | Might have/find an interest in... |
| ----------- | --------------------------------- |
| ALGOSUP | Having students learning: C language, how a processor work, project development, team work... |
| Students | Learning new knowledge by enjoying working on an unique project |

#### ➭ <ins>2.3.3 Project Roles</ins>

| Role | Description | Name |
|---|---|---|
| Project Manager | Is in charge of organization, planing and budgeting. <br> Ensure the communication within the team  <br> Keep the team motivated.  | Thibaud MARLIER |
| Program Manager | Makes sure the project meets client's expectations. <br> Is the intermediary between the client and the development team. <br> Is responsible for writing the Functional Specifications. | Quentin CLÉMENT |
| Tech Lead | Makes the technical decision in the project.<br> Translates the Functional Specification into Technical Specifications. <br> Does code review. | Aurélien FERNANDEZ |
| Software Engineer | Writes the code. <br> Writes documentation. <br> Participate in the technical choices. | Malo ARCHIMBAUD <br> <br> Mathis KAKAL|
| Quality Assurance |  Tests all the functionalities of a product to find bugs and issues. <br> Document bugs and issues. <br> Defines the test strategy and write the test plan. <br> Checks that issues have been fixed. | Arthur LEMOINE |

#### ➭ <ins>2.3.4 Project Reviewers</ins>

External project reviewers have been appointed by the project owner to review our specifications and give us feedback.

### 2.4 Project Plan

#### ➭ <ins>2.4.1 Retroplanning</ins>

![Retroplanning.png](/Documents/Img/FunctionalSpecifications/Retroplanning.png)

#### ➭ <ins>2.4.2 Milestones</ins>

| Milestone                        | Deadline                   |
| -------------------------------- | -------------------------- |
| Functional Specifications V1     | Tuesday, January 30th 2024 |
| Technical Specifications V1      | Friday, February 9th 2024  |
| Final Product | Friday, February 23rd 2024 |
| Oral Presentation | Friday, March 1st 2024     |

#### ➭ <ins>2.4.3 Dependencies</ins>

Functional Specifications require the call for tender and a clear understanding of the client's needs and expectations.

Technical Specifications require the Functional Specifications to be validated by the client.

The development phase requires some prior understanding of the target technologies defined in the technical specifications before being begun.

#### ➭ <ins>2.4.4 Resources/Help/Financial plan</ins>

=> The team (6 people)

=> TODO: X working hours: 3 hours of work in a half day, 6 team members, X half days until the release of the final product (working hours on personal time not included)

=> 1 computer per team member

=> Teachers

=> ALGOSUP's library

=> Similars projects on the internet

#### ➭ <ins>2.4.5 Assumptions/Constraints</ins>

| Assumptions |
|---|
| We assume ALGOSUP will provide answers to our mails within a day. |
| We assume team members will be working the number of hours they are supposed to. |

| Constraints |
|---|
| We have to code in C. |
| We can't use any external library beside C standard libraries. |

## 3. Virtual Processor Architecture
  
Our intended audience consists of beginners without expertise in intricate operations and instructions. Hence, we embrace the philosophy of "if an operation can be broken down into simpler ones, avoid unnecessary complexity."

The RISC approach aligns closely with this philosophy, featuring a reduced set of straightforward instructions. This alignment led us to choose the RISC-V architecture as the inspiration for our project.

### 3.1 Registers

The ALGORISK processor use an architecture able to read 32-bit instructions and data. \
It has 31 mutable registers, each 32-bit wide and one constant register (named `r0`) containing the value 0.
Those registers are named from `r0` to `r31`. \
The first 16 registers handle integer values and the next 16 handle floating-point values.

Three more register types are used for specific purposes:
- `pc` (program counter): Holds the address in memory of the next instruction to be fetched.
- `ir` (instruction register): Holds the current instruction being executed.
- `csr` (Control and status register): Holds the processor's configurations, it contains possible extensions of the instruction set, the informations of the constructor, of the architecture, and of the implementation. Currently 3 csr are present in our processor.

Our CSRs are:
| Name | Description|
|---|---|
| mepc | Machine exception program counter: When an exception occurs, the program counter (PC) value at the time of the exception is saved in the MEPC register.|
| mcause | Machine cause: It holds the cause of the most recent exception.|
| uepc | User exception program counter: It is similar to the two precedent registers, it stores the value of the program counter after an exception has occurred.|

### 3.2 ALU

This processor also contains an ALU (Arithmetic Logic Unit) which will be a versatile unit performing all the operations. It plays a central role in executing assembly instructions, ensuring flexibility and efficiency across diverse tasks.

## 4. Assembly Language

### 4.1 Sections

A typical ALGORISK assembly program will be divided into two sections:
- **Data section**: Contains the program's data, such as variables and constants.
- **Code section**: Contains the program's instructions.

<ins>Data section:</ins>

The data section is delimited by the `.data` directive and the declaration of a constant or a variable will be done like that:

```
.data
    myVariable: .type value
```

The different types of data will be:
- `.byte`: 8-bit signed integer
- `.half`: 16-bit signed integer
- `.word`: 32-bit signed integer
- `.float`: 32-bit floating-point number
- `.string`: null-terminated string
- `.alloc`: allocate the number of bytes specified by the following integer in memory.

To declare arrays, you have to specify both the data type and the values for each element.

Examples:
```
.data
    myByte: .byte 255 // max value for a byte
    myHalf: .half 32767 // max value for a half
    myWord: .word 2147483647 // max value for a word
    myFloat: .float 3.402823466e+38 // max value for a float
    myString: .string "Hello, ALGORISK users!" // the max length depends on the available space in memory
    myAlloc: .alloc // the max length depends on the maximum contiguous free space in memory

    myArray: .word 1, 2, 3, 4, 5 // an array of 5 words
```

It's important to note that there are no explicitly unsigned types. The signedness of the data is often determined by the context in which it is used. \
For instance, when loading or storing data using specific instructions, the signedness is inferred from the type of instruction being used (signed and unsigned instructions will be explained in the following part). \
Always consider the context and the specific requirements of the instruction when working with different data types in RISC-V assembly.

<ins>Code section:</ins>

The code section is delimited by the `.code` directive and the declaration of a constant or a variable will be done like that:

### 4.2 Instruction types and binary formats

Instructions are divided into 6 types: \
R-Type, I-Type, S-Type, B-Type, U-Type, and J-Type.

Here are how they are encoded in 32-bits binary:

![InstructionFormats.png](/Documents/Img/FunctionalSpecifications/InstructionFormats.png)

**1. Opcode (opcode):**
- Purpose: The opcode field specifies the general category or class of the instruction.
- Function: It distinguishes between different instruction types, such as R-Type, I-Type, S-Type, B-Type, U-Type, and J-Type. It is crucial for the processor to identify the broad class of operation the instruction belongs to.
- Length: 7 bits
- Example: In the R-Type instruction add, the opcode specifies that it is an arithmetic addition operation.

**2. Funct3 (funct3):**
- Purpose: The funct3 field is used to provide additional information about the operation within a specific instruction type.
- Function: It refines the instruction classification by indicating the exact operation or variant within a group of instructions.
- Length: 3 bits
- Example: In the I-Type instruction addi (add immediate), funct3 specifies the specific arithmetic operation, like addition, subtraction, logical operations, etc.

**3. Funct7 (funct7):**
- Purpose: The funct7 field is typically found in R-Type instructions and is used for extended functionality or to provide additional information.
- Function: It refines the operation specified by the opcode and funct3 fields. It allows for more detailed control or differentiation between certain instructions of the same type.
- Length: 7 bits
- Example: In the R-Type instruction add, funct7 might be used to distinguish between different types of addition operations, such as signed or unsigned addition.

**4. Destination Register (rd):**
- Purpose: The rd field designates the destination register where the result of the operation is stored.
- Function: It specifies the register address where the result will be written, and it is crucial for identifying the target location for the operation's output.
- Length: 5 bits
- Example: In the R-Type instruction add, rd determines the register where the sum will be stored.

**5. Source Register 1 (rs1):**
- Purpose: The rs1 field identifies the first source register, providing one of the operands for the operation.
- Function: It specifies the register number from which data is fetched, serving as a source for the arithmetic or logical operation.
- Length: 5 bits
- Example: In the R-Type instruction add, rs1 is the register supplying one of the numbers to be added.

**6. Source Register 2 (rs2):**
- Purpose: The rs2 field identifies the second source register, providing another operand for the operation.
- Function: It specifies the register number from which additional data is fetched, playing a role similar to rs1.
- Length: 5 bits
- Example: In the R-Type instruction add, rs2 is the register supplying the second number to be added.

**7. Immediate Value (imm[]):**
- Purpose: The immediate value represents a constant or an offset used in the instruction.
- Function: It is a binary value that provides additional data for certain types of instructions, such as I-Type, S-Type, B-Type, U-Type, and J-Type. It complements registers in defining operands or offsets.
- Length: 
  - I-Type: 12 bits
  - S-Type: Immediate is split into two parts: imm[11:5] and imm[4:0]
  - B-Type: Immediate is split into four parts: imm[12] and imm[10:5] and imm[4:1] and imm[11]
  - U-Type: 20 bits
  - J-Type: 20 bits
- Example: In the I-Type instruction addi (add immediate), imm[] specifies the constant value to be added to the register.

These fields collectively define the operands, destinations, and additional information needed for each instruction in ALGORISK assembly language.

### 4.3 Instructions Set Architecture

| Category | Instruction | Expanding | Description | Syntax | Type | Func3 | Func7 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **Base Integer** | `add` | | Adds the contents of two registers and stores the result in a register | `add rd, r1, r2` | R-Type | 000 | 0000000 |
| | `addi` | **Add Immediate** | Adds an immediate value to a register and stores the result in a register | `addi rd, r1, immediate` | I-Type | 000 | |
| | `sub` | **Subtract** | Subtracts the contents of two registers and stores the result in a register | `sub rd, r1, r2` | R-Type | 000 | 0100000 |
| | `and` | | Performs a bitwise AND operation on the values of two registers and stores the result in a register | `and rd, r1, r2` | R-Type | 111 | 0000000 | 
| | `andi` | **And Immediate** | Performs a bitwise AND operation on the values of a register and an immediate and stores the result in a register | `andi rd, r1, immediate` | I-Type | 111 | |
| | `or` | | Performs a bitwise OR operation on the values of two registers and stores the result in a register | `or rd, r1, r2` | R-Type | 110 | 0000000 |
| | `ori` | **Or Immediate** | Performs a bitwise OR operation on the values of a register and an immediate and stores the result in a register | `ori rd, r1, immediate` | I-Type | 110 | |
| | `xor` | **Exclusive Or** | Performs a bitwise XOR operation on the values of two registers and stores the result in a register | `xor rd, r1, r2` | R-Type | 100 | 0000000 |
| | `xori` | **Exclusive Or Immediate** | Performs a bitwise XOR operation on the values of a register and an immediate and stores the result in a register | `xori rd, r1, immediate` | I-Type | 100 | |
| | `sll` | **Shift Left Logical** | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | `sll rd, r1, r2` | R-Type | 001 | 0000000 |
| | `slli` | **Shift Left Logical Immediate** | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | `slli rd, r1, immediate` | I-Type | 001 | |
| | `srl` | **Shift Right Logical** | Makes a logical shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | `srl rd, r1, r2` | R-Type | 101 | 0000000 |
| | `srli` | **Shift Right Logical Immediate** | Makes a logical shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register | `srli rd, r1, immediate` | I-Type | 101 | |
| | `sra` | **Shift Right Arithmetic** | Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | `sra rd, r1, r2` | R-Type | 101 | 0100000 |
| | `srai` | **Shift Right Arithmetic Immediate** | Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register | `srai rd, r1, immediate` | I-Type | 101 | |
| | `ilt?` | **Is Less Than?** | Compares the signed values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 | `ilt rd, r1, r2` | I-Type | 010 | |
| | `ilti?` | **Is Less Than Immediate?** | Compares the signed value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 | `ilti rd, r1, immediate` | I-Type | 010 | |
| | `iltu?` | **Is Less Than Unsigned?** | Compares the unsigned values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 | `iltu rd, r1, r2` | I-Type | 011 | |
| | `iltui?` | **Is Less Than Unsigned Immediate?** | Compares the unsigned value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 | `iltui rd, r1, immediate` | I-Type | 011 | |
| | `jie` | **Jump If Equal** | Jumps to a label if two registers are equal | `jie r1, r2, label` | B-Type | 001 | |
| | `jine` | **Jump If Not Equal** | Jumps to a label if two registers are not equal | `jine r1, r2, label` | B-Type | 101 | |
| | `jige` | **Jump If Greater or Equal** | Jumps to a label if the signed value of the first register is greater than or equal to the signed value of the second register | `jige r1, r2, label` | B-Type | 011 | |
| | `jigeu` | **Jump If Greater or Equal Unsigned** | Jumps to a label if the unsigned value of the first register is greater than or equal to the unsigned value of the second register | `jigeu r1, r2, label` | B-Type | 111 | |
| | `jile` | **Jump If Less or Equal** | Jumps to a label if the signed value of the first register is less than or equal to the signed value of the second register | `jile r1, r2, label` | B-Type | 010 | |
| | `jileu` | **Jump If Less or Equal Unsigned** | Jumps to a label if the unsigned value of the first register is less than or equal to the unsigned value of the second register | `jileu r1, r2, label` | B-Type | 110 | |
| | `jal` | **Jump And Link** | Jumps to a label and stores the return address in a register | `jal rd, label` | J-Type | | |
| | `jalr` | **Jump And Link Register** | Adds an offset to a register and jumps to the address stored in the register, stores the return address in a register | `jalr rd, r1, offset` | J-Type | | |
| | `syscall` | **System Call** | This transfers control to the operating system, and the system call handler performs the necessary actions (the syscall instruction does not take any operands) | `syscall` | Special | | |
| | `break` | | Generates a breakpoint exception, which can be used for debugging | `break` | Special | | |
| | `lb` | **Load Byte**<sup>1</sup> | Loads a signed byte from memory into a register, the address in memory must be specified as an operand | `lb rd, address` | I-Type | | |
| | `lbu` | **Load Byte**<sup>1</sup> **Unsigned** | Loads an unsigned byte from memory into a register, the address in memory must be specified as an operand | `lbu rd, address` | I-Type | | |
| | `lh` | Load Halfword<sup>2</sup> | Loads a signed halfword from memory into a register, the address in memory must be specified as an operand | `lh rd, address` | I-Type | | |
| | `lhu` | **Load Halfword**<sup>2</sup> **Unsigned** | Loads an unsigned halfword from memory into a register, the address in memory must be specified as an operand | `lhu rd, address` | I-Type | | |
| | `lw` | **Load Word**<sup>3</sup> | Loads a word from memory into a register, the address in memory must be specified as an operand | `lw rd, address` | I-Type | | |
| | `lui` | **Load Upper Immediate** | Loads an immediate value into the upper 20 bits of a register, the lower 12 bits are set to 0 | `lui rd, immediate` | U-Type | | |
| | `auipc` | **Add Upper Immediate to PC** | Adds an immediate value to the upper 20 bits of the program counter, the lower 12 bits are set to 0 | `auipc rd, immediate` | U-Type | | |
| | `sb` | **Store Byte**<sup>1</sup> | Stores the lower 8 bits of a register into memory, the address in memory must be specified as an operand | `sb rd, address` | S-Type | | |
| | `sh` | **Store Halfword**<sup>2</sup> | Stores the lower 16 bits of a register into memory, the address in memory must be specified as an operand | `sh rd, address` | S-Type | | |
| | `sw` | **Store Word**<sup>3</sup> | Stores the lower 32 bits of a register into memory, the address in memory must be specified as an operand | `sw rd, address` | S-Type | | |
| **Integer Multiplication and Division** | `mul` | | Multiplies the contents of two registers and stores the result in a register | `mul rd, r1, r2` | R-Type | 000 | 0000001 |
| | `mulh` | **Multiply High** | Multiplies the contents of two registers and stores the upper 32 bits of the result in a register | `mulh rd, r1, r2` | R-Type | 001 | 0000001 |
| | `mulhu` | **Multiply High Unsigned** | Multiplies the unsigned value of two registers and stores the upper 32 bits of the result in a register | `mulhu rd, r1, r2` | R-Type | 011 | 0000001 |
| | `mulhsu` | **Multiply High Signed Unsigned** | Multiplies the signed value of a register with the unsigned value of another register and stores the upper 32 bits of the result in a register | `mulhsu rd, r1, r2` | R-Type | 010 | 0000001 |
| | `div` | **Divide** | Divides the contents of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) | `div rd, r1, r2` | R-Type | 100 | 0000001 |
| | `divu` | **Divide Unsigned** | Divides the unsigned value of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) | `divu rd, r1, r2` | R-Type | 101 | 0000001 |
| | `rem` | **Remainder** | Divides the contents of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) | `rem rd, r1, r2` | R-Type | 110 | 0000001 |
| | `remu` | **Remainder Unsigned** | Divides the unsigned value of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) | `remu rd, r1, r2` | R-Type | 111 | 0000001 |

<sup>1</sup> a byte is 8 bits \
<sup>2</sup> a halfword is 2 bytes, so 16 bits \
<sup>3</sup> a word is 2 halfwords, so 4 bytes, so 32 bits

`addi r2, r1, 0`

This instruction is equivalent to a `mov` instruction in x86 assembly. As `r1 + 0 = r1`, the content of r1 will be copied in r2.

## 5. From ALGORISK assembly to executable

### 5.1 Preprocessor

The preprocessor is a quick step where the C program will divide the assembly code into two main parts, the data section and the code section. \
Whenever the preprocessor encounters a line starting with a dot followed by the keyword `data` or `code`, the preprocessor will break down the assembly and separe both sections. Meaning, everything which is in `.data` will be kept in memory but not executed as there's no instructions given into this section, except for data initialisation.

Once the preprocessing process has went through the the data section and once variables have been initialised, the preprocessing process will then go through the `.code` section.
This is the part where all the code is put, where instructions that the user wants to pass to the processing unit is. As variables have previously been initialised and kept in memory, we can reuse them in the code section.
During the whole process, if the preprocessor encounters a comment `\\`, the preprocessing unit will remove whatever is after on the line. And will be then ignore during all the remaining processes.

```
\\ This a comment
```

TODO:

### 5.2 Interpreter

The role of the interpreter is to verify line by line if the program is convertible into machine code. \
If it is, it will launch the assembling process. \
If not, it means there are errors and so the interpreter will print the number of errors followed by the line number and the corresponding error message.

![InterpreterDiagram.png](/Documents/Img/FunctionalSpecifications/InterpreterDiagram.png)

#### ➭ <ins>5.2.1 Instruction error</ins>

It first verifies if the name of the instruction corresponds to one of the instructions in the instruction set. \
If not it throws an error in the containing the line number and the incorrect instruction. 

**<ins>Example:</ins>**

Here is an example of an incorrect instruction declared at line 10:

```
ad r1, r2, r3
```

The interpreter will throw the following error:
```
Error at line 10: unknown instruction "ad"
```

#### ➭ <ins>5.2.2 Operand error</ins>

Every instruction is categorized under an instruction type (as defined in the instruction set), which outlines the expected number of operands and their respective types (such as registers, immediates, labels, etc.). The interpreter is responsible for validating the correctness of the operand count and their types. If an error is found, the interpreter will throw an error containing the line number and why the instruction is incorrect.

**<ins>Example:</ins>**

Here is an example of an instruction with too many operands declared at line 10:

```
add r1, r2, r3, r4
```

The interpreter will throw the following error:
```
Error at line 10: instruction "add" expects 3 operands, received other than 3
```
It will work the same if the instruction has too few operands.

Here is an example of an instruction with an incorrect operand type declared at line 10:

```
add r1, r2, rr3
```

The interpreter will throw the following error:
```
Error at line 10: instruction "add" expects operand 3 to be a register, received "rr3"
```

#### ➭ <ins>5.2.3 Variable declaration error</ins>

Moreover, the preprocessor checks if the initialised data are well within the maximum range of 32-bit. If the data is over 32 bits, the preprocessor will break the program and print an error.  
The preprocessor will throw the following error:
```
Error at line 10: Initialised variable is over 32-bit.
```
Furthermore, if the data is initialised as an unsigned value, the preprocessor, will break down the program and throw an error, as it is necessary to initialise data as unsigned as instructions specify whether an integer or a float is signed or unsigned.
The interpreter will throw the following error:
```
Error at line 5: Syntax error.
``` 
Moreover, during the preprocessing process, the preprocessor will check if a label is never used during execution time, to optimize the program and gain space in memory. If it is unused, the label will be ignored by the program and then go on to the next label.

### 5.3 Assembler

When the interpreter has verified that the program is correct, the assembling process begins.

A binary file is created and the assembler transforms each instruction into a 32-bit binary code as defined [previously](#42-instruction-types-and-binary-formats). They will be stored in the binary file in the same order as they are in the assembly file.

**Example:**

Let's perform three operations in RISC-V assembly: load a value from memory into a register, put an immediate value into another register, and finally, add the two registers and store the result in a third register.

**ALGORISK Assembly Code:**
```assembly
lw x1, 0(x2)       # Load the value from memory at address 0 into register x1
li x3, 10          # Load immediate value 10 into register x3
add x4, x1, x3     # Add the values in x1 and x3, store the result in x4
```

**Binary Representation:**
- Load Word (lw):
  ```
  Assembly: lw x1, 0(x2)
  Binary:  0000000 00010 00001 00000 0000011
  ```
- Load Immediate (li):
  ```
  Assembly: li x3, 10
  Binary:  0000000 00000 00011 00000 0000011
  ```
- Addition (add):
  ```
  Assembly: add x4, x1, x3
  Binary:  0000000 00011 00100 00001 0110011
  ```

**Binary File:**
```
000000000010000010000000000110000000000000001100000000001100000000001100100000010110011
```

It seems totally abstract for human eyes, but this is how the processor will read the program.

These binary representations follow the RISC-V instruction format for the given instruction types (I-Type for `lw` and `li`, R-Type for `add`). The opcode, funct3, funct7, and immediate fields are populated based on the specific instructions and their operands.

### 5.4 Execution

#### ➭ <ins>5.4.1 Loader</ins>

The loader takes the binary file generated by the assembler and loads it into memory. It interprets the binary instructions and stores them at the specified memory addresses. The program counter (pc) is initialized to the starting address of the code section, and the loader iterates through the binary instructions, placing them in memory as it advances the program counter.

If there are data sections, the loader also allocates space in memory for variables and initializes them with the specified values.

The loader ensures that the program counter is appropriately updated after each instruction is loaded, allowing for sequential execution of the program. Additionally, it sets up the stack and other necessary components of memory management.

#### ➭ <ins>5.4.2 Execution Unit</ins>

The execution unit is responsible for fetching instructions from memory, decoding them, and executing the corresponding operations. It includes the Arithmetic Logic Unit (ALU) for arithmetic and logical operations, as well as other functional units for tasks such as memory access and control flow handling.

During the execution phase, the processor reads the binary instructions from memory, decodes the opcode and operand fields, and performs the specified operations. The program counter is updated to point to the next instruction in memory.

Control and status registers (csr), such as pc, ir, mepc, mcause, and uepc, play crucial roles in managing program flow, handling exceptions, and maintaining the state of the processor.

The execution unit interprets instructions based on the opcode and operands, directing the flow of the program through branches, jumps, and other control flow mechanisms.

#### ➭ <ins>5.4.3 Exception handling</ins>

Exception handling is an integral aspect of the ALGORISK processor's execution unit. The processor actively monitors for various exceptional conditions that may arise during program execution, such as arithmetic overflow, memory access violation, invalid instructions, division by zero, page faults, illegal instructions, system calls, alignment check issues, floating-point errors, and machine check exceptions.

Upon detecting an exception, the processor initiates a series of actions. It saves the current state, including the program counter, in the appropriate control and status register (CSR). For instance, the mepc (Machine Exception Program Counter) stores the program counter value at the time of the exception, while the mcause (Machine Cause) register holds information about the cause of the exception.

Exception handling involves transferring control to specific exception handlers, each tailored to address particular types of exceptions. These handlers are designed to carry out tasks such as error logging, recovery procedures, or program termination based on the nature of the exception encountered.

**Specific Exception Details:**

| Exception | Description | Handling |
|---|---|---|
| Arithmetic Overflow | Raised when an arithmetic operation results in a value exceeding the representable range. | The processor detects overflow conditions and responds by triggering an exception and updating status flags. |
| Memory Access Violation | Occurs when attempting to access memory outside the allowed range. | The processor identifies out-of-bounds memory access, triggering an exception and involving memory protection mechanisms. |
| Invalid Instruction | Triggered when encountering an undefined or invalid instruction. | The processor recognizes and manages invalid instructions by raising an exception and taking corrective actions. |
| Division by Zero | Raised when attempting to divide a number by zero. | The processor detects division by zero conditions and handles them by raising an exception. |
| Page Fault | Pertains to virtual memory systems and occurs when a requested page is not present in physical memory. | The processor, in collaboration with the operating system, manages page faults by loading the required page into memory. |
| Illegal Instruction | Occurs when attempting to execute an instruction not allowed in the current context or privilege level. | The processor detects and manages illegal instructions by raising an exception, often leading to a trap into the operating system. |
| System Call | Invoked when a software interrupt, often initiated by a system call instruction, occurs to transfer control to the operating system. | The processor recognizes system call instructions, triggers a switch to privileged mode, and executes the corresponding kernel routine. |
| Alignment Check | Raised when a memory access operation is attempted on an address that does not satisfy the required alignment. | The processor detects misaligned memory accesses and raises an exception or performs corrective actions. |
| Floating-Point | Related to floating-point arithmetic operations, includes conditions like overflow, underflow, and invalid operations. | The processor monitors floating-point operations and raises exceptions when exceptional conditions occur. |
| Machine Check | Indicates a hardware error or malfunction detected by the processor. | The processor responds to machine check exceptions by triggering error handling mechanisms and halting or signaling the system. |


#### ➭ <ins>5.4.4 System calls</ins>

System calls (syscall) allow the ALGORISK program to interact with the underlying operating system. When a syscall instruction is encountered, the processor transfers control to the operating system, which then executes the necessary system call routine. This enables tasks such as file I/O, network communication, or other interactions with the environment.

## 6. Debugger

To spot unintentional behavior of the code, a debugger is implemented.

During debugger execution, it processes the code until it encounters a breakpoint, which, in our language, is set using the break instruction. Starting from the breakpoint up to the program's end or until the user manually halts the program, the debugger showcases the contents stored in the registers and the segment of memory used at the current line both before and after the instruction at that line.

To proceed to the next line, the user must press a key, such as Enter or the Spacebar. The displayed information is limited to the state of registers and memory, intentionally avoiding overwhelming the user with excessive details.

```
// code

line 1    addi, r1, r0, 3
line 2    addi, r2, r0, 4
line 3    break
line 4    add r3, r1, r2
line 5    addi r4, r3, 0

// code
```

The example above is how the break instruction should be used. In this scenario, the user wants to verify what is happening from the line with the add instruction. He puts a break before the line and launches the debugger. The debugger then displays the state of the registers and what they contain, instruction per instruction.
This is what the debugger displays in the terminal.
txt
r3 = 7, r1 = 3, r2 =4
r4 = 7, r3 = 7
As what is presented above is a very minimal debugger, the next step is to create a more complete graphical interface. In this interface, in addition to the state of the registers, the memory is also displayed. This makes it easier for the user to track where he is in the program.
|Memory|registers or memory adress|value|
|---|---|---|
|add r3, r1, r2|r1|3|
|addi r4, r3, 0|r2|4|
|...|r3|7|
The registers or the memory addresses that are displayed change depending on which one is being used.

## 7. Plugin

To continue in this willingness to make programming and computer science more accessible to everyone, a plugin for Visual Studio Code named "ALGORISK for VS Code" will be implemented. 

#### ➭ <ins>3.5.1 Color highlighting</ins>

The plugin highlights each type of keyword with a different color. This allows the user to quickly identify the different parts of the code. Here is what each color will represent:

**Sections**: #006EB3 \
**Instructions**: #4EC3E0 \
**Labels**: #FF6720 \
**Destination register**: #250E62 \
**Immediates**: #E0004D \
**Memory adresses**: #FCE300 \
**Register operands**: #FFFFFF or #000000 (depending on the background color)

#### ➭ <ins>3.5.2 Snippets</ins>

TODO:

## 8. Conclusion

<div align="right"><a href="#table-of-contents"><img src="Documents/Img/FunctionalSpecifications/back.png" width="35px"></a></div>

## 9. Appendix

### 9.1 Architecture Benchmark

|   Architecture  |   Licensing  |   Design  |   Type  |   Bits  |   Registers (Excluding FP/Vector)  |   Endianness  |   Pipelining and execution Strategy  |   Micro-Code (aka firmware - induces variable length instructions)  |   Branch Evaluation  |   Instruction Encoding  |   Market Segment/Application  |   Typical Applications  |   Ecosystem Support  |   ISA Extensibility  |   Supports SIMD  |   Concurrency and Parallelism features  |   Fault Tolerance and error correction Features  |   Hardware Acceleration Capabilities  |   Support for Virtualization and security features  |   Scalability  |   Extensions  |   Power Efficiency Strategy  |   Memory Model  |   Max # Operands  |   Version  |   Introduced  |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|   8080  |   Developed and marketed by Intel.  |   CISC  |   Register–Memory  |   8  |   7  |   Little  |   It did not have advanced pipelining; operations were more sequential.  |   It utilized micro-operations, but the concept of microcode in the 8080 differed from modern implementations.  |   Condition register  |   Variable (8 to 24 bits)  |   The 8080 was a general-purpose microprocessor, pivotal in the development of early personal computers and arcade games.  |   Early personal computers, including the Altair 8800, and arcade games like Space Invaders.  |   Significant impact on the early computing ecosystem, influenced many subsequent designs.  |   It had a more advanced instruction set compared to its predecessor, the 8008, but was not designed for extensibility in the modern sense.  |   No support for SIMD.  |   Limited; it was primarily a single-core, single-thread processor.  |   Basic error handling, but not advanced fault tolerance features.  |   Not applicable in the context of modern hardware acceleration.  |   Not a primary focus of the architecture.  |   Limited scalability; designed for simple, general-purpose applications.  |     |   Power efficiency was not a primary concern at the time of its development.  |   The 8080 could address up to 64 KB of memory.  |   2  |     |   1974  |
|   x86  |   Developed by Intel, with AMD also producing x86 processors under a cross-licensing agreement.  |   CISC  |   Register–Memory  |   16, 32, 64   (16→32→64)  |   8 (+ 4 or 6 segment reg.) (16/32-bit)   	16 (+ 2 segment reg. gs/cs) (64-bit)   	32 with AVX-512   |   Little  |   Modern x86 processors have complex pipelining and super-scalar execution.  |   Uses microcode for complex instruction decoding and execution.  |   Condition code  |   Variable (8086 ~ 80386: variable between 1 and 6 bytes /w MMU + intel SDK, 80486: 2 to 5 bytes with prefix, pentium and onward: 2 to 4 bytes with prefix, x64: 4 bytes prefix, third party x86 emulation: 1 to 15 bytes w/o prefix & MMU . SSE/MMX: 4 bytes /w prefix AVX: 8 Bytes /w prefix)  |   Designed for a wide range of applications from personal computers to servers.  |   Broad range, including personal computing, enterprise servers, and high-performance computing.  |   One of the most widely supported architectures with a vast ecosystem of software and hardware.  |   The x86 instruction set has been extensively extended over the years.  |   Modern x86 processors support various SIMD extensions.  |   Supports multi-threading and multi-core processing.  |   Advanced error correction and fault tolerance, especially in server-grade processors.  |   Modern x86 CPUs include various hardware acceleration features like integrated graphics, encryption, and vector processing.  |   Strong support for virtualization and comprehensive security features.  |   Highly scalable, from low-power mobile devices to high-performance servers.  |   x87, IA-32, MMX, 3DNow!, SSE,   SSE2, PAE, x86-64, SSE3, SSSE3, SSE4,   BMI, AVX, AES, FMA, XOP, F16C  |   Modern x86 processors include various power efficiency technologies.  |   Supports complex memory management techniques.  |   2 (integer)   3 (AVX)   4 (FMA4 and VPBLENDVPx)  |     |   1978  |
|   ARC  |   Developed by ARC International, specifics of the licensing model are not detailed.  |   RISC  |   Register–Register  |   16/32/64 (32→64)  |   16 or 32 including SP   user can increase to 60  |   Bi  |   As a RISC-based architecture, it likely employs efficient pipelining but specific strategies are not detailed.  |   The use of micro-code in instruction execution is not explicitly mentioned.  |   Compare and branch  |   Variable (16- or 32-bit)  |   Primarily used in embedded systems, notably in SoCs for diverse applications like storage, digital home, mobile, automotive, and IoT.  |   Used in a wide range of embedded applications, including IoT and automotive systems.  |   Supported by a suite of development tools, indicating a robust ecosystem.  |   Notable for its extensible ISA, allowing custom instructions and modifications.  |   Not explicitly stated, but being a modern architecture, some SIMD capabilities could be expected.  |   Designed for embedded applications, might have limited parallel processing features.  |   Specifics on fault tolerance and error correction are not detailed.  |   Allows for extensibility with custom instructions, possibly for hardware acceleration purposes.  |   Not explicitly mentioned, likely minimal given its embedded system focus.  |   Highly configurable and extensible, indicating good scalability for various applications.  |   APEX User-defined instructions  |   Tailored for embedded systems, it likely emphasizes power efficiency, but specifics are not provided.  |   Details on the memory model are not provided.  |   3  |   ARCv3  |   1996  |
|   ARM/A32  |   ARM Ltd. develops the architecture and licenses it to other companies for physical device manufacturing.  |   RISC  |   Register–Register  |   32  |   15  |   Bi  |   ARM architectures typically utilize efficient pipelining strategies, characteristic of RISC designs.  |   ARM architectures typically do not use micro-code, contributing to their simplicity and efficiency.  |   Condition code  |   Fixed (32-bit)  |   ARM processors are widely used in portable devices like smartphones, laptops, and embedded systems due to their low cost, power efficiency, and minimal heat generation.  |   Ranging from embedded systems to desktops and servers, ARM processors are versatile and used in a variety of applications, including the world's fastest supercomputers.  |   ARM has a robust ecosystem, supported by a wide range of tools and software.  |   ARM architectures are known for their extensibility, supporting various instruction sets.  |   ARM architectures include SIMD extensions, particularly Neon for multimedia processing.  |   ARM processors incorporate features like simultaneous multithreading for improved performance and fault tolerance.  |   ARM designs include fault tolerance features, although specifics vary across different versions.  |   ARM architectures provide extensions for multimedia processing and may include other hardware acceleration features.  |   ARM architectures offer security extensions like TrustZone.  |   The ARM architecture is highly scalable, suiting a wide range of applications.  |   NEON, Jazelle, VFP,   TrustZone, LPAE  |   ARM processors are designed for low power consumption, an essential feature for mobile and embedded devices.  |   ARM uses a 32-bit data bus and has a 26-bit or larger address space, depending on the version.  |   3  |   ARMv1–v9  |   1983  |
|   Arm64/A64  |   ARM Ltd. develops the architecture and licenses it to other companies for physical device manufacturing.  |   RISC  |   Register–Register  |   64  |   32 (including the stack pointer/"zero" register)  |   Bi  |   The ARM/A64, being a RISC architecture, employs efficient pipelining strategies typical of such designs.  |   Generally does not use micro-code, adding to its efficiency.  |   Condition code  |   Fixed (32-bit), Variable (32-bit or 64-bit for FMA4 with 32-bit prefix)  |   It's widely used in various devices, including smartphones, laptops, and embedded systems, and also in high-performance computing like servers and supercomputers.  |   ARM/A64 is versatile, found in lightweight, portable devices as well as in high-performance computing environments.  |   Backed by a robust ecosystem of tools and software.  |   Known for its extensible instruction set, accommodating various instruction sets.  |   It includes SIMD extensions, with Neon being a notable example for enhanced multimedia processing.  |   The architecture supports simultaneous multithreading for improved performance and fault tolerance.  |   Specific fault tolerance features vary across different ARM versions.  |   It offers extensions for multimedia processing and potentially other hardware acceleration capabilities.  |   Includes security extensions, notably TrustZone.  |   The architecture is scalable, fitting a wide range of application needs.  |   SVE and SVE2  |   Designed for low power consumption, crucial for mobile and embedded devices.  |   Employs a 32-bit data bus and has a 26-bit or larger address space, depending on the version.  |   3  |   ARMv8-A  |   2011  |
|   AVR  |   Proprietary, owned by Microchip Technology.  |   RISC  |   Register–Register  |   8  |   32   16 on "reduced architecture"  |   Little  |   Features a two-stage, single-level pipeline for efficient instruction execution.  |   Typically does not use micro-code in its operation.  |   Condition register,   skip conditioned   on an I/O or   general purpose   register bit,   compare and skip  |   Variable (mostly 16-bit, four instructions are 32-bit)  |   Widely used in embedded systems, especially in hobbyist and educational settings.  |   Popular in DIY electronics projects, such as Arduino boards.  |   Strong support due to popularity in the DIY community.  |   Limited compared to more advanced architectures.  |   Does not typically support SIMD.  |   Limited support due to its basic architecture.  |   Basic fault tolerance but lacks advanced features.  |   Limited to basic embedded system functionalities.  |   Lacks advanced virtualization and security features.  |   Primarily designed for simple, low-power applications.  |     |   Focused on low-power operation for embedded systems.  |   Uses a modified Harvard architecture.  |   2  |     |   1997  |
|   Blackfin  |   Proprietary, owned by Analog Devices.  |   RISC  |   Register–Register  |   32  |   2 accumulators   8 data registers   8 pointer registers   4 index registers   4 buffer registers  |   Little  |   Employs a RISC microcontroller programming model on a SIMD architecture.  |   Uses variable-length RISC-like instruction set with 16-, 32-, and 64-bit instructions.  |   Condition code  |   Variable (16- or 32-bit)  |   Used in applications requiring DSP and microcontroller functionalities, such as audio and video processing.  |   Suited for real-time multimedia processing and embedded applications.  |   Supported by Analog Devices' toolchains; has seen use in various operating systems and RTOS.  |   High level of expressiveness in the instruction set.  |   Yes, for accelerated video and image processing.  |   Executes up to three instructions per clock cycle, depending on optimization.  |   Includes a Memory Protection Unit (MPU) for basic protection strategies.  |   Has media-processing extensions for video and image compression and decompression algorithms.  |   Limited support; does not support virtual memory or separate memory addresses per process.  |   Tailored for specific applications with various CPU models.  |     |   Designed for low-power operation.  |   Employs a byte-addressable, flat memory map with a Von Neumann architecture approach.  |   3  |     |   2000  |
|   CDC 6000   Central Processor (CP)  |   Proprietary technology of Control Data Corporation.  |   n/a  |   Register–Register  |   60  |   24 (8 18-bit address reg.,   8 18-bit index reg.,   8 60-bit operand reg.)  |   n/a  |   Featured a single CPU with multiple functional units capable of operating in parallel, each working on different instructions simultaneously.  |   Not specifically mentioned, likely due to the technology of the time.  |   Compare and branch  |   Variable (15-, 30-, or 60-bit)  |   Designed for scientific and business data processing, multiprogramming, multiprocessing, remote job entry, time-sharing, and data management.  |   Used primarily in scientific computing and complex data processing tasks.  |   Supported by the SCOPE operating system and had a dedicated programming language, COMPASS.  |   Employed a unique instruction set but was not known for extensibility.  |   Did not support SIMD as it predates this technology.  |   Utilised multiple functional units for parallel processing of instructions.  |   Not explicitly detailed but was a robust system for its time.  |   Included several arithmetic and logic units for efficient processing.  |   Lacked modern virtualization and security features.  |   Various models with different configurations provided scalability in performance.  |   Compare/Move Unit  |   Power efficiency was not a primary concern at the time of its development.  |   Used a central memory for program storage and execution.  |   3  |     |   1964  |
|   Crusoe   (native VLIW)  |   Proprietary technology of Transmeta Corporation.  |   VLIW  |   Register–Register  |   32  |   1 in native push stack mode 6 in x86 emulation +  8 in x87/MMX mode + 50 in rename status   12 integer + 48 shadow + 4 debug in native VLIW mode  |   Little  |   Utilizes a VLIW architecture, executing multiple operations per clock cycle.  |   Uses Code Morphing software for instruction translation.  |   Condition code  |   Variable (64- or 128-bit in native mode, 15 bytes in x86 emulation)  |   Aimed at mobile computing, prioritizing battery life.  |   Geared towards mobile PCs and Internet devices.  |   Focused initially on ultra-light mobile PCs.  |   The software layer can evolve separately from the hardware.  |   Not explicitly detailed.  |   Handles multiple operations each cycle for parallel processing.  |   Specifics not provided.  |   Efficiently executes x86 instructions through software translation.  |   Not clearly specified.  |   Adaptable for future products with potential varying hardware/software partitioning.  |     |   Reduces power consumption through software-based instruction handling.  |   Not explicitly detailed.  |   1  |     |   2000  |
|   Elbrus 2000   (native VLIW)  |   Developed and licensed by MCST.  |   VLIW  |   Register–Register  |   64  |   8–64  |   Little  |   Employs a VLIW architecture capable of executing multiple instructions per clock cycle.  |   Uses a unique software layer for instruction translation and execution.  |   Condition code  |   64  |   Targets diverse computing applications, including security-sensitive environments.  |   Suited for a range of applications, including security-focused systems.  |   Supports various operating systems, including Linux and Windows (via binary translation).  |   Supports two ISAs: Elbrus VLIW and Intel x86.  |   The details regarding SIMD support are not explicitly stated.  |   Executes numerous instructions per clock, allowing for effective parallel processing.  |   Implements dynamic data type-checking for security.  |   Details on specific hardware acceleration features are not provided.  |   Has robust security features, including type-checking for data access.  |   Designed to be versatile across various computing needs.  |   Just-in-time dynamic translation: x87, IA-32, MMX, SSE,   SSE2, x86-64, SSE3, AVX  |   Details on power efficiency are not specifically mentioned.  |   Utilizes a wide data format with caches at different levels.  |   1  |   v6  |   2007  |
|   DLX  |   Open.  |   RISC  |   ?  |   32  |   32  |   Big  |   Employs a simple 5-stage instruction pipeline.  |   Not explicitly mentioned.  |   ?  |   Fixed (32-bit)  |   Mainly used in university-level computer architecture courses.  |   Used as an educational tool for understanding computer architecture.  |   Used in academic settings with supporting materials available.  |   Simplified and modernized version of the Stanford MIPS CPU.  |   SIMD support is not explicitly detailed.  |   Includes data-forwarding and instruction reordering for handling long instructions.  |   Not specified.  |   Does not focus on hardware acceleration.  |   Not a primary focus of the architecture.  |   Primarily a teaching tool, not designed for scalability in practical applications.  |   ?  |   Not a major concern due to its educational nature.  |   Simple 32-bit load/store architecture.  |   3  |   ?  |   1990  |
|   eSi-RISC  |   Licensed as soft IP cores.  |   RISC  |   Register–Register  |   16/32  |   8–72  |   Bi  |   Features a 5-stage pipeline.  |   Not explicitly mentioned.  |   Compare and branch   and condition register  |   Variable (16- or 32-bit)  |   Suited for a wide range of embedded applications.  |   Useful in digital imaging, sensor interfaces, network processors, etc.  |   Supported by a GNU toolchain and Eclipse IDE.  |   Supports configurable instruction sets including integer, floating-point, and fixed-point arithmetic.  |   Offers SIMD operations.  |   Capable of multiprocessing.  |   Not specifically detailed.  |   Supports user-defined instructions for tasks like cryptographic acceleration.  |   Not clearly specified.  |   Scalable across various applications with different core configurations.  |   User-defined instructions  |   Optimized for low power in embedded systems.  |   Utilizes a RISC-like load/store architecture.  |   3  |     |   2009  |
|   iAPX 432[15]  |   Proprietary Intel architecture.  |   CISC  |   Stack machine  |   32  |   0  |     |   Implemented as a stack machine with no general-purpose registers visible to the programmer.  |   Employed complex microcode to support its advanced features.  |     |   Variable (6 to 321 bits)  |   Aimed at high-level language programming, often referred to as a "micromainframe."  |   Intended for advanced operating systems and large applications.  |   Supported by the iMAX 432 operating system written in Ada.  |   Featured a new instruction set architecture significantly different from Intel's previous designs.  |   There is no specific mention of SIMD support.  |   Designed for multiprocessing and multitasking.  |   Supported fault-tolerant systems and had complex hardware and microcode design.  |   Not specifically mentioned.  |   Focused on object-oriented programming and capability-based addressing for security.  |   Had ambitious goals but faced limitations due to its complex design.  |     |   Power efficiency was not a primary concern at the time of its development.  |   Used segmented memory with a large virtual address space.  |   3  |     |   1981  |
|   Itanium   (IA-64)  |   Proprietary to Intel and Hewlett-Packard.  |   EPIC  |   Register–Register  |   64  |   128  |   Bi   (selectable)  |   Incorporates Explicitly Parallel Instruction Computing (EPIC) for efficient instruction execution.  |   Not explicitly mentioned.  |   Condition register  |   Fixed (128-bit bundles with 5-bit template tag and 3 instructions, each 41-bit long)  |   Primarily used in high-end enterprise servers and high-performance computing systems.  |   Suited for high-performance and enterprise-level server environments.  |   Supported by a range of enterprise systems and software.  |   Utilized a new instruction set architecture, distinct from Intel's x86 line.  |   Details on SIMD support are not explicitly mentioned.  |   Designed for parallel processing, with capabilities to execute multiple instructions per cycle.  |   Engineered for high reliability in mission-critical applications.  |   Specific hardware acceleration features are not detailed.  |   Included support for high-end computing but details on virtualization and security features are not specified.  |   Tailored for scalable performance in enterprise and computing systems.  |   Intel Virtualization Technology  |   Focused on performance rather than power efficiency.  |   Adopted a 64-bit addressing model.  |     |     |   2001  |
|   LoongArch  |   Developed by Loongson Technology Corporation Limited.  |   RISC  |   Register–Register  |   32, 64  |   32 (including "zero")  |   Little  |   Features fixed-size instructions with a RISC style, promoting efficiency.  |   The use of micro-code in instruction execution is not explicitly mentioned.  |     |   Fixed (32-bit)  |   Targets various computing applications, including security-sensitive environments.  |   Suited for a range of computing applications with a focus on security.  |   Compatible with mainstream compilers for efficient code generation.  |   Includes a basic part and an expanded part, allowing for optional implementation of each extension.  |   Includes SIMD extensions for CPU-bound application acceleration.  |   Designed for parallel processing with multiple instruction execution per cycle.  |   Not explicitly detailed in the provided resources.  |   Provides extensions for binary translation and virtualization, enhancing execution efficiency.  |   Offers virtualization extensions for operating system virtualization.  |   Scalable across various computing needs with different core configurations.  |     |   Optimized for efficiency, but specific strategies are not detailed.  |   Implements a load-store architecture, typical of RISC designs.  |   4  |     |   2021  |
|   m88k  |   Developed by Motorola.  |   RISC  |   Register–Register  |   32  |     |   Big  |   Featured a RISC design with single-cycle instructions.  |   Not explicitly mentioned.  |     |   Fixed (32-bit)  |   Aimed at high-end markets including telecommunications, artificial intelligence, and graphics.  |   Used in systems requiring high processing power, like supercomputers.  |   Limited, despite attempts to popularize it.  |   Allowed for new functional units without affecting the existing ISA.  |   Not specifically mentioned.  |   Included support for multiprocessing.  |   Details not available.  |   Supported specialized co-processors for customization.  |   Not specifically mentioned.  |   Aimed at high-end applications, but limited success.  |     |   Power efficiency was not a primary concern at the time of its development.  |   Used a Harvard architecture with separate instruction and data caches.  |   3  |     |   1988  |
|   Mico32  |   Open and royalty-free.  |   RISC  |   Register–Register  |   32  |   32  |   Big  |   Features a six-stage pipeline.  |   Not explicitly mentioned.  |   Compare and branch  |   Fixed (32-bit)  |   Primarily used in embedded systems.  |   Suited for a variety of embedded applications.  |   Supported by an open-source toolchain.  |   Allows for a configurable instruction set.  |   SIMD support is not explicitly detailed.  |   No hardware support.  |   Information not provided.  |   Supports user-defined instructions.  |   Not specified.  |   Configurable for different use cases.  |   User-defined instructions  |   Optimized for FPGA, implying efficient power usage.  |   Utilizes a Harvard architecture.  |   3  |   ?  |   2006  |
|   MIPS  |   MIPS architectures are licensed by MIPS Technologies.  |   RISC  |   Register–Register  |   64 (32→64)  |   4–32 (including "zero")  |   Bi  |   Implements a classic RISC pipeline.  |   Not explicitly mentioned.  |   Condition register  |   Fixed (32-bit)  |   Widely used in embedded systems, including routers, residential gateways, and gaming consoles like the PlayStation and Nintendo 64.  |   Found in embedded systems, consumer electronics, and educational platforms.  |   Supported by a wide range of tools and software, especially in the embedded domain.  |   Offers various extensions for different applications.  |   Includes SIMD extensions for improved performance in specific applications.  |   Optimized for efficient parallel processing in embedded systems.  |   Specifics not detailed.  |   Features extensions for graphics and media processing.  |   Not a primary focus of the architecture.  |   Adaptable to both 32-bit and 64-bit implementations.  |   MDMX, MIPS-3D  |   Focuses on efficiency, particularly in embedded applications.  |   Employs a load/store architecture.  |   1–3  |   6  |   1981  |
|   MMIX  |   Open and royalty-free.  |   RISC  |   Register–Register  |   64  |   256  |   Big  |   Implements a RISC design, but specific details on its pipelining strategy are not explicitly mentioned.  |   Not explicitly mentioned.  |   ?  |   Fixed (32-bit)  |   Intended for educational use in computer science, particularly in illustrating machine-level programming aspects.  |   Used primarily as an educational tool.  |   Accompanied by software tools for research and development.  |   Features a unique instruction set for educational purposes.  |   Information on SIMD support is not detailed.  |   Designed to illustrate modern computing concepts but specifics on concurrency are not provided.  |   Not explicitly mentioned.  |   Lacks specific details on hardware acceleration.  |   Not a primary focus of the architecture.  |   More theoretical in nature, designed for educational purposes rather than scalability in practical applications.  |   ?  |   Not a primary concern due to its educational nature.  |   Utilizes a big-endian 64-bit architecture with 256 general-purpose registers.  |   3  |   ?  |   1999  |
|   NS320xx  |   Proprietary to National Semiconductor.  |   CISC  |   Memory–Memory  |   32  |   8  |   Little  |   The architecture follows a CISC model, with a focus on complex instructions.  |   Not explicitly mentioned.  |   Condition code  |   Variable Huffman coded, up to 23 bytes long  |   Aimed at general-purpose computing and embedded systems.  |   Found in various computing systems, including some early workstations.  |   Had some presence in the market with various systems using the architecture.  |   Known for its orthogonal design, allowing flexible instruction applications.  |   No explicit mention of SIMD support.  |   No hardware support, as it was designed for efficient single-threaded operations.  |   Not detailed in available resources.  |   Included coprocessor support, particularly for FPUs and MMUs.  |   Features demand paging virtual memory, a notable aspect for its time.  |   Had versions with improvements, but faced competition from emerging RISC architectures.  |   BitBlt instructions  |   Power efficiency was not a primary concern at the time of its development.  |   Implemented a 24-bit virtual memory system.  |   5  |     |   1982  |
|   OpenRISC  |   Licensed under LGPL/GPL, making it open and royalty-free.  |   RISC  |   Register–Register  |   32, 64  |   16 or 32  |   ?  |   Implements traditional RISC architecture with a load-store, 3-operand model.  |   Not explicitly mentioned.  |   ?  |   Fixed  |   Used in various applications including commercial, academic, and hobbyist projects.  |   Utilized in embedded systems, academic research, and some commercial products.  |   Supported by GNU toolchain, Linux kernel, and various RTOS.  |   Open-source ISA allows for community-driven development and modifications.  |   Offers SIMD instructions for digital signal processing.  |   Has supervisor mode and virtual memory system, with support for multiple processors.  |   Specific details are not provided.  |   Not specifically mentioned.  |   Includes a supervisor mode and memory control.  |   Adaptable in various system implementations.  |   ?  |   Focuses on performance and simplicity, suitable for low power applications.  |   Features a 32/64-bit load-store RISC architecture.  |   3  |   1.4  |   2000  |
|   PA-RISC   (HP/PA)  |   Proprietary technology by Hewlett-Packard.  |   RISC  |   Register–Register  |   64 (32→64)  |   32  |   Big → Bi  |   Implements a RISC design with efficient instruction execution.  |   Not explicitly mentioned.  |   Compare and branch  |   Fixed (32-bit)  |   Used in HP's Unix and industrial computers.  |   Suited for enterprise and high-performance computing systems.  |   Supported various operating systems including Linux and HP-UX.  |   Extended to 64 bits in PA-RISC 2.0.  |   Features SIMD extensions for multimedia applications (MAX, MAX-2).  |   Capable of multiprocessing.  |   Not specifically detailed.  |   Includes multimedia acceleration extensions.  |   Not a primary focus of the architecture.  |   Offers 64-bit extensions, enhancing its scalability.  |   MAX  |   Not explicitly mentioned.  |   Load/Store RISC architecture  |   3  |   2.0  |   1986  |
|   POWER, PowerPC, Power ISA  |   Developed and licensed by the AIM alliance.  |   RISC  |   Register–Register  |   32/64 (32→64)  |   32 GPR, 8 4-bit Condition Fields, Link Register, Counter Register  |   Bi  |   Implements RISC principles with superscalar execution, allowing for multiple instructions per cycle.  |   Not specifically mentioned.  |   Condition code, Branch-Counter auto-decrement  |   Fixed (32-bit), Variable (32- or 64-bit with the 32-bit prefix)  |   Initially intended for personal computers and later popular in embedded systems and game consoles.  |   Used in a wide range of devices, from personal computers to embedded systems and game consoles.  |   Supported by a range of operating systems and software.  |   Evolved over time with new versions and extensions.  |   Includes SIMD extensions like AltiVec.  |   Supports multiprocessing.  |   Not explicitly detailed.  |   Features like AltiVec for enhanced processing capabilities.  |   Not a primary focus of the architecture.  |   Adaptable in both 32-bit and 64-bit forms.  |   AltiVec, APU, VSX, Cell, Floating-point, Matrix Multiply Assist  |   Emphasis on performance, with later versions focusing more on efficiency.  |   Load/Store RISC architecture  |   3 (mostly). FMA, LD/ST-Update  |   3.1  |   1990  |
|   RISC-V  |   Open-source and royalty-free.  |   RISC  |   Register–Register  |   32, 64, 128  |   32 (including "zero")  |   Little  |   RISC-V follows a load-store architecture common to RISC designs.  |   None, instructions are optimized when compiled  |   Compare and branch  |   Variable  |   It's used across various sectors including aerospace, automotive, data centers, and high-performance computing.  |   RISC-V finds use in embedded systems, personal computers, and supercomputers.  |   Supported by open-source operating systems and popular toolchains.  |   Offers a modular ISA allowing for various extensions.  |   SIMD is supported through extensions for enhanced processing.  |   It supports multi-core computing with synchronisation primitives.  |   Specifics are not detailed.  |   The architecture allows for extensions, potentially supporting hardware acceleration.  |   Includes support for virtualization through planned extensions.  |   It's highly scalable due to its modular design.  |   ?  |   Focuses on efficiency for embedded systems.  |   Employs a 32-bit or 64-bit flat address space.  |   3  |   20191213  |   2010  |
|   SPARC  |   Originally developed by Sun Microsystems, now owned by Oracle Corporation.  |   RISC  |   Register–Register  |   64 (32→64)  |   32 (including "zero")  |   Big → Bi  |   Implements a RISC design with a focus on efficient pipelining.  |   Not explicitly mentioned.  |   Condition code  |   Fixed (32-bit)  |   Primarily used in high-performance computing, servers, and enterprise systems.  |   Commonly found in enterprise servers, workstations, and high-performance computing systems.  |   Supported by a range of operating systems and software, particularly in the Unix environment.  |   Evolved over time with various versions and extensions.  |   Includes SIMD extensions for parallel data processing.  |   Designed for high-performance computing with multiprocessing capabilities.  |   Known for its robustness in mission-critical applications.  |   Features like VIS extension for improved media and signal processing.  |   Includes capabilities for virtualization and security in enterprise environments.  |   Highly scalable, suitable for a range of high-performance applications.  |   VIS  |   Focused on high-performance computing rather than power efficiency.  |   Employs a load-store architecture typical of RISC designs.  |   3  |   OSA2017  |   1985  |
|   SuperH (SH)  |   Initially developed by Hitachi, the rights to the SuperH architecture were later transferred to Renesas Electronics.  |   RISC  |   Register–Register   Register–Memory  |   32  |   16  |   Bi  |   SuperH is a RISC architecture known for its efficient pipelining and compact code size, which is beneficial for embedded systems.  |   Not explicitly mentioned.  |   Condition code   (single bit)  |   Fixed (16- or 32-bit), Variable  |   SuperH architectures are mainly used in embedded systems, including automotive, consumer electronics, and computer peripherals.  |   Widely used in automotive control systems, consumer electronics like game consoles, and various embedded devices.  |   Supported by a range of development tools and software, particularly in the embedded systems community.  |   While initially designed for 32-bit processing, the architecture has evolved to include more advanced features over time.  |   Some SuperH processors, like the SH-4 series, support SIMD (Single Instruction, Multiple Data) for multimedia applications.  |   The architecture allows for efficient execution of concurrent processes, which is important in embedded applications.  |   Specifics on fault tolerance and error correction are not widely detailed.  |   Some models have hardware acceleration features for graphics and multimedia processing.  |   Traditionally, SuperH architectures have limited support for virtualization and advanced security features, focusing more on direct hardware interaction in embedded systems.  |   The architecture is scalable across a range of applications, from small microcontrollers to more powerful embedded processors.  |   ?  |   Focuses on energy efficiency, which is critical in embedded and portable devices.  |   SuperH uses a Harvard architecture in some variants, separating code and data buses to improve performance.  |   2  |   ?  |   1994  |
|   System/360   System/370   z/Architecture  |   IBM proprietary technology.  |   CISC  |   Register–Memory   Memory–Memory   Register–Register  |   64 (32→64)  |   16 general   16 control (S/370 and later)   16 access (ESA/370 and later)  |   Big  |   Utilizes a CISC architecture with variable instruction lengths.  |   Not explicitly mentioned.  |   Condition code, compare and branch auto increment, Branch-Counter auto-decrement  |   Variable (16-, 32-, or 48-bit)  |   Used in a wide range of applications, from general business to scientific computing.  |   Mainframe computing, covering a broad spectrum from business to scientific applications.  |   Supported by IBM's extensive software and hardware ecosystem.  |   Featured a fixed instruction set.  |   Not specifically detailed for SIMD support.  |   Its design facilitated concurrent processing.  |   Not prominently highlighted in the architecture.  |   Primarily focused on general-purpose computing, without specific hardware acceleration.  |   Not a primary focus of the architecture.  |   Designed to address a wide range of computing needs.  |     |   Power efficiency was not a primary concern at the time of its development.  |   Complex, supporting various forms of memory management.  |   2 (most)   3 (FMA, distinct   operand facility)   4 (some vector inst.)  |     |   1964  |
|   Transputer  |   Proprietary, developed by Inmos.  |   MISC  |   Stack machine  |   32 (4→64)  |   3 (as stack)  |   Little  |   Featured pipelining but details vary by specific models.  |   Implemented a form of micro-coding but was not a major feature.  |   Compare and branch  |   Variable (8 ~ 120 bytes)  |   Primarily used in parallel computing and embedded systems.  |   Used in scientific computing, real-time systems, and embedded applications.  |   Limited, mostly focused around Inmos and specific industrial applications.  |   Had a unique instruction set, focused on parallel processing; extensibility was limited.  |   Early Transputers did not support SIMD, but later models might have included some SIMD capabilities.  |   Designed for parallel processing, with multiple Transputer units able to be linked together.  |   Basic error detection, but advanced features are model-specific.  |   Limited compared to modern standards but was advanced for its time in parallel processing.  |   Not a primary focus of the architecture.  |   Highly scalable for parallel processing tasks.  |     |   Designed for efficiency in embedded and parallel systems, but not comparable to modern low-power designs.  |   Supported shared memory in multi-Transputer setups.  |   1  |     |   1987  |
|   VAX  |   Proprietary, developed by Digital Equipment Corporation (DEC).  |   CISC  |   Memory–Memory  |   32  |   16  |   Little  |   Early models had limited pipelining, but later models improved on this.  |   Used microcoding to implement its complex instruction set.  |   Condition code, compare and branch  |   Variable  |   Used in servers, mainframe, and minicomputer applications.  |   Enterprise computing, scientific research, and education.  |   Strong in enterprise and educational sectors.  |   Complex instruction set with extensive capabilities, but not easily extensible.  |   No support for SIMD.  |   Limited compared to modern CPUs; focused on single-threaded performance.  |   Included in high-end models for enterprise reliability.  |   General-purpose computing without specific hardware acceleration.  |   Some support in later models, especially for enterprise environments.  |   Limited scalability; primarily scaled up through larger, more powerful systems rather than parallelism.  |     |   Power efficiency was not a primary concern at the time of its development.  |   Complex, supporting various forms of memory management.  |   6  |     |   1977  |
|   Z80  |   Developed by Zilog; widely cloned and used in numerous products.  |   CISC  |   Register–Memory  |   8  |   17  |   Little  |   Simple execution pipeline, primarily single-cycle instructions.  |   Primarily used hardwired logic rather than microcode.  |   Condition register  |   Variable (8 to 32 bits)  |   Widely used in embedded systems, consumer electronics, and early personal computers.  |   Embedded systems, early PCs, gaming consoles, and calculators.  |   Very strong, particularly in the 1980s.  |   Had a simple and effective instruction set but was not designed for extensibility.  |   No support for SIMD.  |   Primarily single-threaded, with no inherent parallelism features.  |   Basic; primarily relied on external systems for fault tolerance.  |   None; it was a straightforward microprocessor.  |   Not a primary focus of the architecture.  |   Limited to single-core configurations with modest performance.  |     |   Relatively power-efficient for its time but not by modern standards.  |   Simple, with a linear address space and limited memory management capabilities.  |   2  |     |   1976  |

<details>
<summary>

#### Sources

</summary>

For almost all Architectures:
https://www.wikipedia.org/

For Crusoe:
https://www.pctechguide.com/cpu-technology/crusoe-transmeta-corps-x86-compatible-vliw-mobile-cpu

For 8080:
https://www.elprocus.com/know-about-architecture-of-the-intel-8080-microprocessor/

</details>
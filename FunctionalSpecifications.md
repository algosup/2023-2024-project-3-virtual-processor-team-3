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
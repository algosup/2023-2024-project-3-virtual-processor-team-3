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
- [3. Virtual Processor](#3-virtual-processor)
  - [3.1 Architecture](#31-architecture)
- [4. Assembly Language](#4-assembly-language)
  - [4.1 Sections](#41-sections)
  - [4.2 Instructions Set Architecture](#42-instructions-set-architecture)
  - [4.3 Instruction types and binary formats](#43-instruction-types-and-binary-formats)
- [5. From ALGORisk assembly to executable](#5-from-algorisk-assembly-to-executable)
  - [5.1 Preprocessor](#51-preprocessor)
  - [5.2 Interpreter](#52-interpreter)
    - [➭ 4.2.1 Instruction error](#-421-instruction-error)
    - [➭ 4.2.2 Operand error](#-422-operand-error)
  - [3.4 Debugger](#34-debugger)
  - [3.5 Plugin](#35-plugin)
- [4. Conclusion](#4-conclusion)

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

We will create a virtual processor in C named NAME, and an easy to use assembly language to run on it. \
The goal is to make programming and computer science more accessible to everyone. \
We want beginners to learn how a computer works at a low level, without being disgusted with too complex and specific instructions. 

#### ➭ <ins>2.2.2 Scope</ins>

| In Scope |
| -------- |
| Create an optimizesd 32-bit virtual processor with 32 registers |
| Invent an assembly language with an explicit instruction set and a clear syntax |
| Execute programs written in ALGORisk assembly on a ALGORisk virtual processor |
| Transform the program's instructions into machine code before executing it | 
| Be able to debug programs written in ALGORisk assembly |
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

=> X working hours: 3 hours of work in a half day, 6 team members, X half days until the release of the final product (working hours on personal time not included)

=> 1 computer per team member

=> Teachers

=> ALGOSUP's library

=> Similiars projects on the internet

#### ➭ <ins>2.4.5 Assumptions/Constraints</ins>

| Assumptions |
|---|
| We assume ALGOSUP will provide answers to our mails within a day. |
| We assume team members will be working the number of hours they are supposed to. |

| Constraints |
|---|
| We have to code in C. |
| We can't use any external library beside C standard libraries. |

## 3. Virtual Processor

<!-- When the user will be willing to execute his program, the following steps will be executed:
- preprocessing
- assembling
- executing 

Order of execution
  open asm file
  read preprocessor directives
    single line comments
    sections
    see if theres more
  read instructions
  output binary file
  open binary with our processor .out-->
  
### 3.1 Architecture

Our intended audience consists of beginners without expertise in intricate operations and instructions. Hence, we embrace the philosophy of "if an operation can be broken down into simpler ones, avoid unnecessary complexity."

The RISC approach aligns closely with this philosophy, featuring a reduced set of straightforward instructions. This alignment led us to choose the RISC-V architecture as the inspiration for our project.

The ALGORisk processor will use an architecture able to read 32-bit instructions and data. \
It will have 31 mutable registers, each 32-bit wide and one constant register (named `r0`) containing the value 0.
Those registers will be named from `r0` to `r31`. \
The first 16 registers will handle integer values and the next 16 will handle floating-point values.

Three more registers will be used for specific purposes:
- `pc` (program counter): Holds the address in memory of the next instruction to be fetched.
- `ir` (instruction register): Holds the current instruction being executed.
- `csr` (Control and status register): Holds the processor's configurations, it contains possible extensions of the instruction set, the informations of the constructor, of the architecture, and of the implementation. Currently 3 csr are present in our processor.

Our CSRs are:
| Name | Description|
|---|---|
| mepc | Machine exception program counter: When an exception occurs, the program counter (PC) value at the time of the exception is saved in the MEPC register.|
| mcause | Machine cause: It holds the cause of the most recent exception.|
| uepc | User exception program counter: It is similar to the two precedent registers, it stores the value of the program counter after an exception has occurred.|

## 4. Assembly Language

### 4.1 Sections

A typical ALGORisk assembly program will be divided into two sections:
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
- `.double`: 64-bit floating-point number
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
    myDouble: .double 1.7976931348623158e+308 // max value for a double
    myString: .string "Hello, ALGORisk users!" // the max length depends on the available space in memory
    myAlloc: .alloc // the max length depends on the maximum contiguous free space in memory

    myArray: .word 1, 2, 3, 4, 5 // an array of 5 words
```

It's important to note that there are no explicitly unsigned types. The signedness of the data is often determined by the context in which it is used. \
For instance, when loading or storing data using specific instructions, the signedness is inferred from the type of instruction being used (signed and unsigned instructions will be explained in the following part). \
Always consider the context and the specific requirements of the instruction when working with different data types in RISC-V assembly.

<ins>Code section:</ins>

The code section is delimited by the `.code` directive and the declaration of a constant or a variable will be done like that:

### 4.2 Instructions Set Architecture

| Category | Instruction | Expanding | Description | Syntax | Type |
| --- | --- | --- | --- | --- | --- |
| **Base Integer** | `add` | | Adds the contents of two registers and stores the result in a register | `add rd, r1, r2` | R-Type |
| | `addi` | **Add Immediate** | Adds an immediate value to a register and stores the result in a register | `addi rd, r1, immediate` | I-Type |
| | `sub` | **Subtract** | Subtracts the contents of two registers and stores the result in a register | `sub rd, r1, r2` | R-Type |
| | `and` | | Performs a bitwise AND operation on the values of two registers and stores the result in a register | `and rd, r1, r2` | R-Type |
| | `andi` | **And Immediate** | Performs a bitwise AND operation on the values of a register and an immediate and stores the result in a register | `andi rd, r1, immediate` | I-Type |
| | `or` | | Performs a bitwise OR operation on the values of two registers and stores the result in a register | `or rd, r1, r2` | R-Type |
| | `ori` | **Or Immediate** | Performs a bitwise OR operation on the values of a register and an immediate and stores the result in a register | `ori rd, r1, immediate` | I-Type |
| | `xor` | **Exclusive Or** | Performs a bitwise XOR operation on the values of two registers and stores the result in a register | `xor rd, r1, r2` | R-Type |
| | `xori` | **Exclusive Or Immediate** | Performs a bitwise XOR operation on the values of a register and an immediate and stores the result in a register | `xori rd, r1, immediate` | I-Type |
| | `sll` | **Shift Left Logical** | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | `sll rd, r1, r2` | R-Type |
| | `slli` | **Shift Left Logical Immediate** | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | `slli rd, r1, immediate` | I-Type | 
| | `srl` | **Shift Right Logical** | Makes a logical shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | `srl rd, r1, r2` | R-Type |
| | `srli` | **Shift Right Logical Immediate** | Makes a logical shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register | `srli rd, r1, immediate` | I-Type |
| | `sra` | **Shift Right Arithmetic** | Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | `sra rd, r1, r2` | R-Type |
| | `srai` | **Shift Right Arithmetic Immediate** | Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register | `srai rd, r1, immediate` | I-Type |
| | `ilt?` | **Is Less Than?** | Compares the signed values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 | `ilt rd, r1, r2` | I-Type |
| | `ilti?` | **Is Less Than Immediate?** | Compares the signed value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 | `ilti rd, r1, immediate` | I-Type |
| | `iltu?` | **Is Less Than Unsigned?** | Compares the unsigned values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 | `iltu rd, r1, r2` | I-Type |
| | `iltui?` | **Is Less Than Unsigned Immediate?** | Compares the unsigned value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 | `iltui rd, r1, immediate` | I-Type |
| | `jie` | **Jump If Equal** | Jumps to a label if two registers are equal | `jie r1, r2, label` | B-Type |
| | `jine` | **Jump If Not Equal** | Jumps to a label if two registers are not equal | `jine r1, r2, label` | B-Type |
| | `jige` | **Jump If Greater or Equal** | Jumps to a label if the signed value of the first register is greater than or equal to the signed value of the second register | `jige r1, r2, label` | B-Type |
| | `jigeu` | **Jump If Greater or Equal Unsigned** | Jumps to a label if the unsigned value of the first register is greater than or equal to the unsigned value of the second register | `jigeu r1, r2, label` | B-Type |
| | `jile` | **Jump If Less or Equal** | Jumps to a label if the signed value of the first register is less than or equal to the signed value of the second register | `jile r1, r2, label` | B-Type |
| | `jileu` | **Jump If Less or Equal Unsigned** | Jumps to a label if the unsigned value of the first register is less than or equal to the unsigned value of the second register | `jileu r1, r2, label` | B-Type |
| | `jal` | **Jump And Link** | Jumps to a label and stores the return address in a register | `jal rd, label` | J-Type |
| | `jalr` | **Jump And Link Register** | Adds an offset to a register and jumps to the address stored in the register, stores the return address in a register | `jalr rd, r1, offset` | J-Type |
| | `syscall` | **System Call** | This transfers control to the operating system, and the system call handler performs the necessary actions (the syscall instruction does not take any operands) | `syscall` | Special |
| | `break` | | Generates a breakpoint exception, which can be used for debugging | `break` | Special |
| | `lb` | **Load Byte**<sup>1</sup> | Loads a signed byte from memory into a register, the address in memory must be specified as an operand | `lb rd, address` | I-Type |
| | `lbu` | **Load Byte**<sup>1</sup> **Unsigned** | Loads an unsigned byte from memory into a register, the address in memory must be specified as an operand | `lbu rd, address` | I-Type |
| | `lh` | **Load Halfword**<sup>2</sup> | Loads a signed halfword from memory into a register, the address in memory must be specified as an operand | `lh rd, address` | I-Type |
| | `lhu` | **Load Halfword**<sup>2</sup> **Unsigned** | Loads an unsigned halfword from memory into a register, the address in memory must be specified as an operand | `lhu rd, address` | I-Type |
| | `lw` | **Load Word**<sup>3</sup> | Loads a word from memory into a register, the address in memory must be specified as an operand | `lw rd, address` | I-Type |
| | `lui` | **Load Upper Immediate** | Loads an immediate value into the upper 20 bits of a register, the lower 12 bits are set to 0 | `lui rd, immediate` | U-Type |
| | `auipc` | **Add Upper Immediate to PC** | Adds an immediate value to the upper 20 bits of the program counter, the lower 12 bits are set to 0 | `auipc rd, immediate` | U-Type |
| | `sb` | **Store Byte**<sup>1</sup> | Stores the lower 8 bits of a register into memory, the address in memory must be specified as an operand | `sb rd, address` | S-Type |
| | `sh` | **Store Halfword**<sup>2</sup> | Stores the lower 16 bits of a register into memory, the address in memory must be specified as an operand | `sh rd, address` | S-Type |
| | `sw` | **Store Word**<sup>3</sup> | Stores the lower 32 bits of a register into memory, the address in memory must be specified as an operand | `sw rd, address` | S-Type |
| **Integer Multiplication and Division** | `mul` | | Multiplies the contents of two registers and stores the result in a register | `mul rd, r1, r2` | R-Type |
| | `mulh` | **Multiply High** | Multiplies the contents of two registers and stores the upper 32 bits of the result in a register | `mulh rd, r1, r2` | R-Type |
| | `mulhu` | **Multiply High Unsigned** | Multiplies the unsigned value of two registers and stores the upper 32 bits of the result in a register | `mulhu rd, r1, r2` | R-Type |
| | `mulhsu` | **Multiply High Signed Unsigned** | Multiplies the signed value of a register with the unsigned value of another register and stores the upper 32 bits of the result in a register | `mulhsu rd, r1, r2` | R-Type |
| | `div` | **Divide** | Divides the contents of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) | `div rd, r1, r2` | R-Type |
| | `divu` | **Divide Unsigned** | Divides the unsigned value of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) | `divu rd, r1, r2` | R-Type |
| | `rem` | **Remainder** | Divides the contents of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) | `rem rd, r1, r2` | R-Type |
| | `remu` | **Remainder Unsigned** | Divides the unsigned value of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) | `remu rd, r1, r2` | R-Type |

<sup>1</sup> a byte is 8 bits \
<sup>2</sup> a halfword is 2 bytes, so 16 bits \
<sup>3</sup> a word is 2 halfwords, so 4 bytes, so 32 bits

`addi r2, r1, 0`

This instruction is equivalent to a `mov` instruction in x86 assembly. As `r1 + 0 = r1`, ghe content of r1 will be copied in r2.

### 4.3 Instruction types and binary formats

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

These fields collectively define the operands, destinations, and additional information needed for each instruction in ALGORisk assembly language.

## 5. From ALGORisk assembly to executable

### 5.1 Preprocessor

The preprocessor is a quick step where the C program will divide the assembly code into two main parts, the data section and the code section. \
Whenever the preprocessor encounters a line starting with a dot followed by the keyword `data` or `code`, the preprocessor will break down the assembly and separe both sections. Meaning, everything which is in `.data` will be kept in memory but not executed as there's no instructions given into this section, except for data initialisation.
<!-- Moreover, the preprocessor checks if the initialised data are well within the maximum range of 32-bit. If the data is over 32 bits, the preprocessor will break the program and print an error.  
The preprocessor will throw the following error:
```
Error at line 5: Initialised variable is over 32-bit.
```
Furthermore, if the data is initialised as an unsigned value, the preprocessor, will break down the program and throw an error, as it is necessary to initialise data as unsigned as instructions specify whether an integer or a float is signed or unsigned.
The interpreter will throw the following error:
```
Error at line 5: Syntax error.
``` -->
<!-- Moreover, during the preprocessing process, the preprocessor will check if a label is never used during execution time, to optimize the program and gain space in memory. If it is unused, the label will be ignored by the program and then go on to the next label. -->

Once the preprocessing process has went through the the data section and once variables have been initialised, the preprocessing process will then go through the `.code` section.
This is the part where all the code is put, where instructions that the user wants to pass to the processing unit is. As variables have previously been initialised and kept in memory, we can reuse them in the code section.
During the whole process, if the preprocessor encounters a comment `\\`, the preprocessing unit will remove whatever is after on the line. And will be then ignore during all the remaining processes.
```
\\ This a comment
```

TODO:

### 5.2 Interpreter

The interpreter reads the assembly file and verify if the syntax is correct. When it has read the whole file, it will print the number of errors and each error with the line number and the error message. If there is no error, it will translate the assembly code into binary code and write it into a file.

![InterpreterDiagram.png](/Documents/Img/FunctionalSpecifications/InterpreterDiagram.png)

#### ➭ <ins>4.2.1 Instruction error</ins>

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

#### ➭ <ins>4.2.2 Operand error</ins>

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

### 3.4 Debugger

### 3.5 Plugin

## 4. Conclusion

<div align="right"><a href="#table-of-contents"><img src="Documents/Img/FunctionalSpecifications/back.png" width="35px"></a></div>
# Functional Specifications

<details>
<summary>

## Table of Contents

</summary>

- [Functional Specifications](#functional-specifications)
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
  - [3.1 Virtual Processor](#31-virtual-processor)
    - [3.1.1 Architecture](#311-architecture)
  - [3.2 Assembly Language](#32-assembly-language)
      - [➭ 3.2.1 Sections](#-321-sections)
      - [➭ 3.2.2 Instructions Set Architecture](#-322-instructions-set-architecture)
    - [3.3 Interpreter](#33-interpreter)
    - [3.4 Debugger](#34-debugger)
  - [4. Conclusion](#4-conclusion)

</details>

## 1. Glossary

| Term              | Definition | Source/s |
| ----------------- | ---------- | -------- |
| Assembly Language |            |          |
| Virtual Processor |            |          |
| Interpreter       |            |          |
| RISC              |            |          |

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

<!-- TODO: -->

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

## 3.1 Virtual Processor

<!-- When the user will be willing to execute his program, the following steps will be executed:
- preprocessing
- assembling
- executing -->
  
### 3.1.1 Architecture

Our intended audience consists of beginners without expertise in intricate operations and instructions. Hence, we embrace the philosophy of "if an operation can be broken down into simpler ones, avoid unnecessary complexity."

The RISC approach aligns closely with this philosophy, featuring a reduced set of straightforward instructions. This alignment led us to choose the RISC-V architecture as the inspiration for our project.

The ALGORisk processor will use an architecture able to read 32-bit instructions and data. \
It will have 31 mutable registers, each 32-bit wide and one constant register (named `r0`) containing the value 0.
Those registers will be named from `r0` to `r31`. \
The first 16 registers will handle integer values and the next 16 will handle floating-point values.

Three more registers will be used for specific purposes:
- `pc` (program counter): Holds the address in memory of the next instruction to be fetched.
- `ir` (instruction register): Holds the current instruction being executed.
- `csr` TODO:

## 3.2 Assembly Language

#### ➭ <ins>3.2.1 Sections</ins>

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

#### ➭ <ins>3.2.2 Instructions Set Architecture</ins>

| Category | Instruction | Expanding | Description | Syntax |
| --- | --- | --- | --- | --- |
| **Base Integer** | `add` | | Adds the contents of two registers and stores the result in a register | `add rd, r1, r2` |
| | `addi` | **Add Immediate** | Adds an immediate value to a register and stores the result in a register | `addi rd, r1, immediate` |
| | `sub` | **Substract** | Subtracts the contents of two registers and stores the result in a register | `sub rd, r1, r2` |
| | `and` | | Performs a bitwise AND operation on the values of two registers and stores the result in a register | | `and rd, r1, r2` |
| | `andi` | **And Immediate** | Performs a bitwise AND operation on the values of a register and an immediate and stores the result in a register | `andi rd, r1, immediate` |
| | `or` | | Performs a bitwise OR operation on the values of two registers and stores the result in a register | `or rd, r1, r2` |
| | `ori` | **Or Immediate** | Performs a bitwise OR operation on the values of a register and an immediate and stores the result in a register | `ori rd, r1, immediate` |
| | `xor` | **Exclusive Or** | Performs a bitwise XOR operation on the values of two registers and stores the result in a register | | `xor rd, r1, r2` |
| | `xori` | **Exclusive Or Immediate** | Performs a bitwise XOR operation on the values of a register and an immediate and stores the result in a register | `xori rd, r1, immediate` |
| | `sll` | **Shift Left Logical** | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | `sll rd, r1, r2` |
| | `slli` | **Shift Left Logical Immediate** | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register | `slli rd, r1, immediate` | 
| | `srl` | **Shift Right Logical** | Makes a logical shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | `srl rd, r1, r2` |
| | `srli` | **Shift Right Logical Immediate** | Makes a logical shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register | `srli rd, r1, immediate` |
| | `sra` | **Shift Right Arithmetic** | Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register | `sra rd, r1, r2` |
| | `srai` | **Shift Right Arithmetic Immediate** | Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register | `srai rd, r1, immediate` |
| | `ilt?` | **Is Less Than?** | Compares the signed values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 | `ilt rd, r1, r2` |
| | `ilti?` | **Is Less Than Immediate?** | Compares the signed value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 | `ilti rd, r1, immediate` |
| | `iltu?` | **Is Less Than Unsigned?** | Compares the unsigned values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 | `iltu rd, r1, r2` |
| | `iltui?` | **Is Less Than Unsigned Immediate?** | Compares the unsigned value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 | `iltui rd, r1, immediate` |
| | `jie` | **Jump If Equal** | Jumps to a label if two registers are equal | `jie r1, r2, label` |
| | `jine` | **Jump If Not Equal** | Jumps to a label if two registers are not equal | `jine r1, r2, label` |
| | `jige` | **Jump If Greater or Equal** | Jumps to a label if the signed value of the first register is greater than or equal to the signed value of the second register | `jige r1, r2, label` |
| | `jigeu` | **Jump If Greater or Equal Unsigned** | Jumps to a label if the unsigned value of the first register is greater than or equal to the unsigned value of the second register | `jigeu r1, r2, label` |
| | `jile` | **Jump If Less or Equal** | Jumps to a label if the first register is less than or equal to the second register | `jile r1, r2, label` |
| | `jileu` | **Jump If Less or Equal Unsigned** | Jumps to a label if the unsigned value of the first register is less than or equal to the unsigned value of the second register | `jileu r1, r2, label` |
| | `jal` | **Jump And Link** | Jumps to a label and stores the return address in a register | `jal rd, label` |
| | `jalr` | **Jump And Link Register** | Adds an offset to a register and jumps to the address stored in the register, stores the return address in a register | `jalr rd, r1, offset` |
| | `syscall` | **System Call** | This transfers control to the operating system, and the system call handler performs the necessary actions (the syscall instruction does not take any operands) | `syscall` | 
| | `break` | | Generates a breakpoint exception, which can be used for debugging | `break` |
| | `lb` | **Load Byte**<sup>1</sup> | Loads a signed byte from memory into a register, the address in memory must be specified as an operand | `lb rd, address` |
| | `lbu` | **Load Byte**<sup>1</sup> **Unsigned** | Loads an unsigned byte from memory into a register, the address in memory must be specified as an operand | `lbu rd, address` |
| | `lh` | **Load Halfword**<sup>2</sup> | Loads a signed halfword from memory into a register, the address in memory must be specified as an operand | `lh rd, address` |
| | `lhu` | **Load Halfword**<sup>2</sup> **Unsigned** | Loads an unsigned halfword from memory into a register, the address in memory must be specified as an operand | `lhu rd, address` |
| | `lw` | **Load Word**<sup>3</sup> | Loads a word from memory into a register, the address in memory must be specified as an operand | `lw rd, address` |
| | `lui` | **Load Upper Immediate** | Loads an immediate value into the upper 20 bits of a register, the lower 12 bits are set to 0 | `lui rd, immediate` |
| | `auipc` | **Add Upper Immediate to PC** | Adds an immediate value to the upper 20 bits of the program counter, the lower 12 bits are set to 0 | `auipc rd, immediate` |
| | `sb` | **Store Byte**<sup>1</sup> | Stores the lower 8 bits of a register into memory, the address in memory must be specified as an operand | `sb rd, address` |
| | `sh` | **Store Halfword**<sup>2</sup> | Stores the lower 16 bits of a register into memory, the address in memory must be specified as an operand | `sh rd, address` |
| | `sw` | **Store Word**<sup>3</sup> | Stores the lower 32 bits of a register into memory, the address in memory must be specified as an operand | `sw rd, address` |
| **Integer Multiplication and Division** | `mul` | | Multiplies the contents of two registers and stores the result in a register | `mul rd, r1, r2` |
| | `mulh` | **Multiply High** | Multiplies the contents of two registers and stores the upper 32 bits of the result in a register | `mulh rd, r1, r2` |
| | `mulhu` | **Multiply High Unsigned** | Multiplies the unsigned value of two registers and stores the upper 32 bits of the result in a register | `mulhu rd, r1, r2` |
| | `mulhsu` | **Multiply High Signed Unsigned** | Multiplies the signed value of a register with the unsigned value of another register and stores the upper 32 bits of the result in a register | `mulhsu rd, r1, r2` |
| | `div` | **Divide** | Divides the contents of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) | `div rd, r1, r2` |
| | `divu` | **Divide Unsigned** | Divides the unsigned value of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) | `divu rd, r1, r2` |
| | `rem` | **Remainder** | Divides the contents of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) | `rem rd, r1, r2` |
| | `remu` | **Remainder Unsigned** | Divides the unsigned value of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) | `remu rd, r1, r2` |

<sup>1</sup> a byte is 8 bits \
<sup>2</sup> a halfword is 2 bytes, so 16 bits \
<sup>3</sup> a word is 2 halfwords, so 4 bytes, so 32 bits

Order of execution
  open asm file
  read preprocessor directives
    single line comments
    sections
    see if theres more
  read instructions
  output binary file
  open binary with our processor .out

`addi r2, r1, 0`

This instruction is equivalent to a `mov` instruction in x86 assembly. As `r1 + 0 = r1`, ghe content of r1 will be copied in r2.

### 3.3 Interpreter

### 3.4 Debugger

## 4. Conclusion
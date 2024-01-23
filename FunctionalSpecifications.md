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
  - [3. Functional Requirements](#3-functional-requirements)
    - [3.1 Virtual Processor](#31-virtual-processor)
      - [➭ 3.1.1 RISC-V Architecture](#-311-risc-v-architecture)
      - [➭ 3.1.1 Architecture](#-311-architecture)
    - [3.2 Assembly Language](#32-assembly-language)
      - [➭ 3.2.1 Comparison with x86 Assembly](#-321-comparison-with-x86-assembly)
      - [➭ 3.2.2 Instructions Set](#-322-instructions-set)
      - [Registers](#registers)
      - [Instructions](#instructions)
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

<!-- - Create a fast and efficient virtual processor
- Invent a painless assembly language with all the essential instructions
- Create a debugger to analyse ALGORisk assembly programs in real time -->

| In Scope |
| -------- |
| Create a 32-bit virtual processor with 32 registers |
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

#### ➭ <ins>2.3.3 Project Roles</ins>

#### ➭ <ins>2.3.4 Project Reviewers</ins>

External project reviewers have been appointed by the project owner to review our specifications and give us feedback.

### 2.4 Project Plan

#### ➭ <ins>2.4.1 Retroplanning</ins>

#### ➭ <ins>2.4.2 Milestones</ins>

| Milestone                        | Deadline                   |
| -------------------------------- | -------------------------- |
| Functional Specifications V1     | Tuesday, January 30th 2024 |
| Technical Specifications V1      | Friday, February 9th 2024  |
| POC (Pre-MVP)                    | TODEFINE                   |
| MVP (Alpha release)              | TODEFINE                   |
| Final Product (Beta release)     | Friday, February 23rd 2024 |
| Oral Presentation (Beta Release) | Friday, March 1st 2024     |

#### ➭ <ins>2.4.3 Dependencies</ins>

The POC requires some prior understanding of the target technologies before being developed, meaning that its development will probably start on week 3.

The MVP requires the POC to be made first to estimate task difficulty and set objectives' viability.

The technical specifications require the functional specifications to be validated by the client.

The development phase requires the technical specifications to be finished.

#### ➭ <ins>2.4.4 Resources/Help/Financial plan</ins>

=> The team (6 people)

=> X working hours: 3 hours of work in a half day, 6 team members, X half days until the release of the final product (working hours on personal time not included)

=> 1 computer per team member

=> Teachers

=> ALGOSUP's library

#### ➭ <ins>2.4.5 Assumptions/Constraints</ins>

| Assumptions                                                       |
| ----------------------------------------------------------------- |
| We assume ALGOSUP will provide answers to our mails within a day. |

| Constraints                                                    |
| -------------------------------------------------------------- |
| We have to code in C.                                          |
| We can't use any external library beside C standard libraries. |

## 3. Functional Requirements

<!-- When the user will be willing to execute his program, the following steps will be executed:
- preprocessing
- assembling
- executing -->

### 3.1 Virtual Processor

#### ➭ <ins>3.1.1 RISC-V Architecture</ins>

Our objective being to create an assembly for educational uses we chose to use an architecture similar to the RISC-V32's architecture. This choice was supported by multiple advantages of this architecture compared to the x86 architecture:

- Instructions are present in smaller member, thus new developers are not drown into a torrent of information from the manual.
- The complexity of the architecture is reduced in front of the x86 architecture.
- The RISC-V architecture is build for scalability and is energy efficient. 
- The instruction set has lower latency than the x86 architecture. 
  
#### ➭ <ins>3.1.1 Architecture</ins>

Our architecture will be similar to the RISC-V32 architecture, yet we will not have the same. Here is a list of the changes of our own architecture:

 - We will use 16 registers, 8 of them will be used for integers and the last 8 will be used for float values.
 - Our instructions set will be renamed to increase the overall readability.
 - The instruction set will be reduced to the most basic ones.
 - A few instructions will be modified to allow uses that weren't possible in other archtecture.

### 3.2 Assembly Language

#### ➭ <ins>3.2.1 Comparison with x86 Assembly</ins>

As asked by the sponsor, we will create our assembly and associate a key word (notation) to each required instruction. \
In comparison, here are what those requirements would look like in x86 assembly:

1. Storing an immediate value into a register: `MOV reg, immediate`
2. Copying the value of a register into another register: `MOV destination_reg, source_reg`
3. Reading the value of the memory at the address contained by a register and storing it into another register: `MOV destination_reg, [source_reg]`
4. Storing the value of a register into memory at the address contained by another register: `MOV [destination_reg], source_reg`
5. Comparing the content of registers: `CMP reg1, reg2`
6. Jumping unconditionally to a label: `JMP label`
7. Jumping conditionally to a label: `Jcc label` (cc represents a condition code like JE for equal, JNE for not equal, etc.)
8. Calling a subroutine: `CALL subroutine`
9. Returning from a subroutine: `RET`
10. The 4 basic arithmetic operations:
   - Addition: `ADD destination_reg, source_reg/immediate`
   - Subtraction: `SUB destination_reg, source_reg/immediate`
   - Multiplication: `IMUL destination_reg, source_reg/immediate`
   - Division: `IDIV divisor_reg/immediate`
11. The 4 basic logical operations:
   - OR: `OR destination_reg, source_reg/immediate`
   - AND: `AND destination_reg, source_reg/immediate`
   - XOR: `XOR destination_reg, source_reg/immediate`
   - NOT: `NOT reg`

Note: Replace placeholders such as `reg`, `immediate`, `destination_reg`, `source_reg`, `label`, `subroutine`, and `divisor_reg` with the specific registers, immediate values, labels, subroutines, or registers containing divisor values as needed in your program.

#### ➭ <ins>3.2.2 Instructions Set</ins>

#### Registers

r0: a constant zero that can't be changed
r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15: general purpose registers

#### Instructions

| Category | Instruction | Description | Syntax |
|---|---|---|---|
| **Arithmetic Operations** | Add | Adds the contents of two registers and stores the | result in a register | `add r3, r1, r2` |
| | Add immediate | Adds a value to a register and stores the | result in a register | `addi r2, r1, immediate` |
| | Sub | Subtracts the contents of two registers and stores | the result in a register | `sub r3, r1, r2` |
| | Multiply | Multiplies the contents of two registers and | stores the result in a register | `mul r3, r1, r2` |
| | Multiply immediate | Multiplies a value with a register | and stores the result in a register | `muli r2, r1, | immediate` |
| | Divide | Divides the contents of two registers and stores the result in a register | `div r3, r1, r2` |
| | Divide immediate | Divides a value with a register and stores the result in a register | `divi r2, r1, immediate` |
| **Memory Management** | Load word | Loads a word from memory into a register | `lw r1, memory` |
| | Store word | Stores a word from a register into memory | `sw r1, memory` |
| | Load byte | Loads a byte from memory into a register | `lb r1, memory` |
| | Store byte | Reads a byte from memory and stores it in a register | `sb r1, memory` |
| **Conditions Statements** | 
<!-- | add | Adds two values and stores the result in a register | `add r3, reg1, ` |
| addi | Adds a value to a register and stores the result in a register | `addi reg1, reg2, immediate` |
| sub | Subtracts two values and stores the result in a register | `sub reg1, reg2` |
| mul | Multiplies two values and stores the result in a register | `mul reg1, reg2` |
| muli | Multiplies a value with a register and stores the result in a register | `muli reg1, reg2, immediate` |
| div | Divides two values and stores the result in a register | `div reg1, reg2` |
| divi | Divides a value with a register and stores the result in a register | `divi reg1, reg2, immediate` |
| lw | Loads a word from memory into a register | `lw reg1, reg2` |
| sw | Stores a word from a register into memory | `sw reg1, reg2` |
| lb | Loads a byte from memory into a register | `lb reg1, reg2` |
| sb | Reads a byte from memory and stores it in a register | `sb reg1, reg2` |
| beq | Branches to a label if two registers are equal | `beq reg1, reg2, label` |
| bne | Branches to a label if two registers are not equal | `bne reg1, reg2, label` |
| blt | Branches to a label if the first register is less than the second register | `blt reg1, reg2, label` |
| bgt | Branches to a label if the first register is greater than the second register | `bgt reg1, reg2, label` |
| ble | Branches to a label if the first register is less than or equal to the second register | `ble reg1, reg2, label` |
| bge | Branches to a label if the first register is greater than or equal to the second register | `bge reg1, reg2, label` |
| j | Jumps to a label | `j label` |
| jal | Jumps to a label and stores the return address in register 31 | `jal label` |
| jr | Jumps to the address stored in a register | `jr reg` | -->

add sub and or xor sll srl sra slt sltu addi andi ori xori slli srli srai slti sltiu beq bne bge bgeu blt bltu jal jalr ecall ebreak lb lbu lh lhu lw lui auipc fence sb sh sw
mulh div mul rem remu mulhu divu mulhsu

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
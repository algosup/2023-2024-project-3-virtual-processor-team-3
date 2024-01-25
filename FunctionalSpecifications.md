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
      - [➭ 2.2.2 Objectives](#-222-objectives)
      - [➭ 2.2.3 Scope](#-223-scope)
      - [➭ 2.2.4 Deliverables](#-224-deliverables)
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
    - [3.3 Interpreter](#33-interpreter)
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

<!-- TODO: 
The goal of the project is to create a virtual processor and an interpreter for running assembly code on 
that processor. 
The project will be developed in plain, portable, C language without the use of any external library beside 
C standard libraries. We recommend you use gcc as a compiler and Visual Studio Code as IDE. 
 
First, you need to invent a minimal assembly language for your processor. Your instruction set will 
contain at least the following instructions: 
- Storing an immediate value into a register. 
- Copying the value of a register into another register. 
- Reading the value of the memory at the address contained by a register and storing it into another register. 
- Storing the value of a register into memory at the address contained by another register. 
- Comparing the content of registers. 
- Jumping unconditionally to a label. 
- Jumping conditionally to a label. 
- Calling a subroutine. 
- Returning from a subroutine. 
- The 4 basic arithmetic operations: addition, subtraction, multiplication, and division. 
- The 4 basic logical operations: OR, AND, XOR, and NOT. 
 
Your assembly language should be fully described in your functional specification. 
 
Then you need to write a C program that can read a text file containing a program written in your 
assembly dialect and run it. The C program also needs to check that the assembly program is 
semantically valid and detect syntactical errors. 
In order to see that the assembly program is actually running, implement a virtual system call for 
displaying text in a virtual terminal, that can be accessed from the assembly code. You could also display 
the content of registers and have a built-in debugger. 
The way the C program is intended to work should be described in your technical specification. 
 
Finally, you need to write small assembly programs conceptually similar to unit tests to prove that 
everything is working as expected. -->

### 2.2 Project Definition

#### ➭ <ins>2.2.1 Vision</ins>

<!-- We are making our own virtual processor that will run our own assembly language.
We will also make an interpreter that will run the assembly language on the virtual processor. -->

#### ➭ <ins>2.2.2 Objectives</ins>



#### ➭ <ins>2.2.3 Scope</ins>

| In Scope |
| -------- |

| Out of Scope |
| ------------ |

#### ➭ <ins>2.2.4 Deliverables</ins>

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

### 3.3 Interpreter

## 4. Conclusion
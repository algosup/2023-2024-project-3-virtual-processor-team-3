# <h1 align="center">Test Plan</h1>

<p align="right">created : 17/01/2024<br>last modified : 16/02/2024</p>

# 0. Document Review

| Last Review | Reviewer |
| :----: | :----: |
|  |  |

# 1. Introduction

This test plan is designed to prescribe the scope, approach, resources, and schedule of all testing activities for the project Virtual_Processor_Team_3.

This project has for objective to recreate a virtual processor and a corresponding assembly language with basic commands such as arithmetic operations, logical operations, etc.

## 1.1 Scope

### 1.1.1 In Scope

All the feature of the project defined in the [Functional Specification](../functional_specifications.md) are in need to be tested

| Feature | Full Name | Type | Description |
| :--: | :--: | :--: | :--: |
|`mepc`|Machine Execution Program Counter|Control And Status Register|When an exception occurs, the program counter (PC) value at the time of the exception is saved in the MEPC register|
|`mcause`|Machine Cause|Control And Status Register|It holds the cause of the most recent exception|
|`uepc`|User Exception Program Counter|Control And Status Register|It is similar to the two precedent registers, it stores the value of the program counter after an exception has occurred|
|`pc`|Program Counter|Specific Register|Holds the address in memory of the next instruction to be fetched|
|`ir`|Instruction Register|Specific Register|Holds the current instruction being executed|
| `add` | Addition | Assembler Instruction | Adds the contents of two registers and stores the result in a register |
| `addi` | Immediate Addition | Assembler Instruction | Adds an immediate value to a register and stores the result in a register |
| `sub` | Substraction | Assembler Instruction | Subtracts the contents of two registers and stores the result in a register |
| `and` | Logical AND | Assembler Instruction | Performs a bitwise AND operation on the values of two registers and stores the result in a register |
| `andi` | Immediate Logical AND | Assembler Instruction | Performs a bitwise AND operation on the values of a register and an immediate and stores the result in a register |
| `or` | Logical OR | Assembler Instruction | Performs a bitwise OR operation on the values of two registers and stores the result in a register |
| `ori` | Immediate Logical OR | Assembler Instruction | Performs a bitwise OR operation on the values of a register and an immediate and stores the result in a register |
| `xor` | Logical Exlusive OR | Assembler Instruction | Performs a bitwise XOR operation on the values of two registers and stores the result in a register |
| `xori` | Immediate Logical Exclusive OR | Assembler Instruction | Performs a bitwise XOR operation on the values of a register and an immediate and stores the result in a register |
| `sll` | Shift Left Logical | Assembler Instruction | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register |
| `slli` | Immediate Shift Left Logical | Assembler Instruction | Makes a logical shift of the bits of the first register to the left by the number of bits specified in the second register and stores the result in a register |
| `srl` | Shift Right Logical | Assembler Instruction | Makes a logical shift of the bits of the first register to the right by the number of bits specified in the second register and stores the result in a register |
| `srli` | Immediate Shift Right Logical | Assembler Instruction | Makes a logical shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register |
| `sra` | Shift Right Arithmetic | Assembler Instruction | Makes a logical shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register |
| `srai` | Immediate Shift Right Arithmetic | Assembler Instruction | Makes an arithmetic shift of the bits of the first register to the right by the number of bits specified by the immediate and stores the result in a register |
| `ilt?` | Is Less Than | Assembler Instruction | Compares the signed values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 |
| `ilti?` | Immediate Is Less Than | Assembler Instruction | Compares the signed value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 |
| `iltu?` | Is Less Than Unsigned | Assembler Instruction | Compares the unsigned values of two registers, stores 1 if the first register is less than the second register, otherwise stores 0 |
| `iltui?` | Immediate Is Less Than Unsigned | Assembler Instruction | Compares the unsigned value of a register with an immediate, stores 1 if the register is less than the immediate, otherwise stores 0 |
| `jie` | Jump If Equal | Assembler Instruction | Jumps to a label if two registers are equal |
| `jine` | Jump If Not Equal | Assembler Instruction | Jumps to a label if two registers are not equal |
| `jige` | Jump If Greater or Equal | Assembler Instruction | Jumps to a label if the signed value of the first register is greater than or equal to the signed value of the second register |
| `jigeu` | Jump If Greater or Equal Unsigned | Assembler Instruction | Jumps to a label if the unsigned value of the first register is greater than or equal to the unsigned value of the second register |
| `jile` | Jump If Less or Equal | Assembler Instruction | Jumps to a label if the signed value of the first register is less than or equal to the signed value of the second register |
| `jileu` | Jump If Less or Equal Unsigned | Assembler Instruction | Jumps to a label if the unsigned value of the first register is less than or equal to the unsigned value of the second register |
| `jal` | Jump And Link | Assembler Instruction | Jumps to a label and stores the return address in a register |
| `jalr` | Jump And Link Register | Assembler Instruction | Adds an offset to a register and jumps to the address stored in the register, stores the return address in a register |
| `syscall` | System Call | Assembler Instruction | This transfers control to the operating system, and the system call handler performs the necessary actions (the syscall instruction does not take any operands) |
| `break` | Break | Assembler Instruction | Generates a breakpoint exception, which can be used for debugging |
| `lb` | Load Byte | Assembler Instruction | Loads a signed byte from memory into a register, the address in memory must be specified as an operand |
| `lbu` | Load Byte Unsigned | Assembler Instruction | Loads an unsigned byte from memory into a register, the address in memory must be specified as an operand |
| `lh` | Load Halfword | Assembler Instruction | Loads a signed halfword from memory into a register, the address in memory must be specified as an operand |
| `lhu` | Load Halfword Unsigned | Assembler Instruction | Loads an unsigned halfword from memory into a register, the address in memory must be specified as an operand |
| `lw` | Load Word | Assembler Instruction | Loads a word from memory into a register, the address in memory must be specified as an operand |
| `lui` | Load Upper Immediate | Assembler Instruction | Loads an immediate value into the upper 20 bits of a register, the lower 12 bits are set to 0 |
| `auipc` | Add Upper Immediate to PC | Assembler Instruction | Adds an immediate value to the upper 20 bits of the program counter, the lower 12 bits are set to 0 |
| `sb` | Store Byte | Assembler Instruction | Stores the lower 8 bits of a register into memory, the address in memory must be specified as an operand |
| `sh` | Store Halfword | Assembler Instruction | Stores the lower 16 bits of a register into memory, the address in memory must be specified as an operand |
| `sw` | Store Word | Assembler Instruction | Stores the lower 32 bits of a register into memory, the address in memory must be specified as an operand |
| `mul` | Multiply | Assembler Instruction | Multiplies the contents of two registers and stores the result in a register |
| `mulh` | Multiply High | Assembler Instruction | Multiplies the contents of two registers and stores the upper 32 bits of the result in a register |
| `mulhu` | Multiply High Unsigned | Assembler Instruction | Multiplies the unsigned value of two registers and stores the upper 32 bits of the result in a register |
| `mulhsu` | Multiply High Signed Unsigned | Assembler Instruction | Multiplies the signed value of a register with the unsigned value of another register and stores the upper 32 bits of the result in a register |
| `div` | Divide | Assembler Instruction | Divides the contents of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) |
| `divu` | Divide Unsigned | Assembler Instruction | Divides the unsigned value of two registers and stores the result in a register (the destination register has to be from r16 to r31 to handle floats) |
| `rem` | Remainder | Assembler Instruction | Divides the contents of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) |
| `remu` | Remainder Unsigned | Assembler Instruction | Divides the unsigned value of two registers and stores the remainder in a register (the destination register has to be from r16 to r31 to handle floats) |

#### Definition

|Name|Number if Bit|Comparison|
|:-:|:-:|:-:|
|Byte|8|-|
|Halfword|16|2 Byte|
|Word|32|2 Halfword / 4 Byte|

### 1.1.2 Out-Of-Scope

These feature are not to be tested as they are not included in the requirement specifications
- Multy-Threading
- Interrupts
- Atomic Instructions

## 1.2 Quality Objective

### 1.2.1 Primary Objective

The primary objective is to ensure that the project in its entirety meets the full requirements defined in the functional specifications and fit metrics for each quality requierement.

Any changes, additions, or deletion to the requirements document, Functional Specification, or Technical Specification will be documented and tested at the highest level of quality allowed within the remaining time of the project and within the ability of the test team.

### 1.2.2 Secondary Objective

The secondary objective will be to identify and expose all issues and the associated risks, communicate all known issues to the project team and ensure that all these issues are addressed before release.

## 1.3 Roles & Responsibilities

### 1.3.1 Developer(-s)

The team member or members that undertake solution development activities. Responsible for:
1. Developing the solution
2. Conduct Unit testing

### 1.3.2 Tester(-s)
The team member or members that undertake testing, and quality management activities. Responsible for:
1. Writing the test plan
2. Monitoring and managing testing integrity
3. Support and conduct testing activities
4. Communicate to the project team on the current issues in the project

# 2 Test Methodology

## 2.1 Overview

For this project, we will follow an iterative testing strategy, as it will allow us to have testing feedback rapidely and on a regular basis (at each Milestone/Release). It will also allow us to save time on testing after multiple iterations based on experience from past iterations.

We will use usability testing to ensure complience with the user's needs and Unit testing to verify functionality and code coverage.

## 2.2 Usability Testing

The purpose of usability testing is to ensure that the new components and/or features will function in a proper manner that is acceptable to the user.

Usability testing can be coordinated by Tester(-s), but actual testing must be performed by non-testers (**as close to end-users as possible**). Tester(-s) will then review the findings and provide the project team with their evaluation of the impact these changes will have on the testing process and to the project as a whole.

We will use some help from other teams and enrole their QAs or Developers as our users for testing sessions. 

As we know those sessions are time consuming we will also propose that our QAs or Developer help other teams as users.

## 2.3 Unit testing (Multiple)

Unit testing will be conducted by the Developer during code development process to ensure that proper functionality and code coverage have been acheived.

Each function, whatever its porpuse, shall have at least one coresponding unit test that will verify its functionalty with multiple parameters to ensure flawless running of the solution.

## 2.4 Iteration Testing

Iterative development refers to the method which consist in dividing a project into smaller parts, when one is finish, we either iterate over it to enhanced it or implement it and pass to the next one.

The purpose of iterative testing is to complete iterative development by testing at the end of each "Iteration".

In our case, we will run test sessions at each merge in the main branch on the github repository.

## 2.5 Bug Triage

The purpose of the triage is to determine the type of resolution for each bug and to prioritize and determine a schedule for all “To Be Fixed Bugs’. Bug triages will be held throughout all phases of the development cycle and regularly with the time frame being determined by the bug find rate and project schedules.

All members of the team should be involved in these triage meetings to ensure good communication on the matter.

## 2.6 Suspension Criteria & Resumption Requirement

Testing will be suspended if any of the following conditions are met and until they are resolved:
- There is a critical change in the scope of the project which has an impact on the critical path.
- A bug of critical severity on a major feature is discovered.

If one of those conditions is ever met, the Quality Assurance will help the development team resolve the corresponding issue(-s) and/or bug(-s).

## 2.7 Test Completeness

Testing will be considered complete when the following criteria have been met:
- When all team members agree that testing is complete, the solution is stable, and agree that the solution meets functional requirements.
- All test cases have passed.
- All priority 1 & 2 bugs have been resolved and closed.
- Each test case has been signed off as completed by the Quality Assurance.

# 3 Test Deliverables

Bellow is the list of artefacts that should be produced during testing.

|Name|Purpose|Link|
|:-:|:-:|:-:|
|Test Plan||[X](../Testing/test_plan.md)|
|Test Cases||[X](https://github.com/orgs/algosup/projects/23)|
|Bug Reports||[X](../Testing/test_plan.md)|
|Bugs Data Report||[X](../Testing/test_plan.md)|

# 4 Resource & Environment Needs

## 4.1 Testing Tools

Since the project is hosted on GitHub, we will use the GitHub "Issues" feature as a tool to create tickets as bug report and the GitHub "project" feature to handle test cases.


## 4.2 Test Environment

Since there is multiple working environment within the project team. It will allow us to test our solution in different contexts which are defined bellow.

### 4.2.1 Hardware

|Processor|RAM|
|:-|-:|
|Apple M1|8Gb|
|Intel i7|16Gb|

### 4.2.2 Software

|OS|Version|
|:-|-:|
|MacOS|14.3|
|Windows|11|

## 4.3 Bug Severity & Priority Definition

Bug Severity and Priority fields are both very important for categorizing bugs and prioritizing if and when the bugs will be fixed. The bug Severity and Priority levels will be defined in the tables below. Each Bug will be assigned a severity and priority level.

### 4.3.1 Severity List

|Severity ID|Severity Level|Severity Description|
|:-:|:-:|:-:|
|1|Critical|The solution crashes or the bug causes non-recoverable conditions. System crashes, file corruption, or potential data loss, program hangs requiring reboot are all examples of a Severity 1 bug|
|2|High|Major solution component unusable due to failure or incorrect functionality.  Severity 2 bugs cause serious problems such as a lack of functionality, or insufficient or unclear error messages that can have a major impact to the user, prevents other areas of the solution from being tested, etc|
|3|Medium|Incorrect functionality of component or process|
|4|Minor|Incorrect functionality of component or process.  There is a simple work around for the bug if it is Severity 3|

### 4.3.2 Priotity List

|Priority ID|Priority Level|Priority Description|
|:-:|:-:|:-:|
|5|Must Fix|This bug must be fixed immediately; the solution cannot ship with this bug|
|4|Should Fix|These are important problems that should be fixed as soon as possible|
|3|Fix When Have Time|The problem should be fixed within the time available. If the bug does not delay shipping date, then fix it|
|2|Low Priority|It is not important (at this time) that these bugs be addressed.  Fix these bugs after all other bugs have been fixed|
|1|Trivial|Enhancements/ Good to have features incorporated; just are out of the current scope|

# 5 Terms / Acronyms

|Term / Acronym|Definition|
|:-:|:-:|
|BUG|Any error or defect that cause the solution or hardware to malfunction|
|CODE COVERAGE|/|
# Project Charter - Virtual Processor - Team 3

| **Document Name**  | Project Charter           |
|--------------------|---------------------------|
| **Document Owner** | MARLIER Thibaud           |
|**Last Modification (Date)**| 01/17/2024        |

<details>

<summary style="font-size:1.2em; font-weight:bold;">Table Of Content:</summary>

- [Project Charter - Virtual Processor - Team 3](#project-charter---virtual-processor---team-3)
  - [Project Overview](#project-overview)
  - [Project Scope](#project-scope)
  - [Team Members](#team-members)
  - [Stakeholders](#stakeholders)
  - [Milestones](#milestones)
  - [Deliverables](#deliverables)
  - [Budget](#budget)
  - [Risks And Assumptions](#risks-and-assumptions)
  - [Quality Standards](#quality-standards)
  - [Communication Plans](#communication-plans)
  - [Success Criterias](#success-criterias)

</details>

## Project Overview

This project aims to design and create a **virtual processor** and an **interpreter** that will run our **own Assembly language** on that same processor. All developed by **our team**.
Our product will be developed using the **C language**, relying only on the **C standard library**, no other libraries should be used by our team.  
The project officialy started (for the team), the 17th of January. The final product has to be received by the client the 23rd of February.
In short terms, we have to come with an original and new processor and Assembly language. We have to make our dream processor. The processor and Assembly will be aimed to be educative, meaning it should be understandable by everyone, and will help you in the process of learning how a CPU works.  
We will take inspiration of the architecture of the RSIK-V CPU architecture.

## Project Scope

The scope of the **Virtual Processor project** is to create along with a working processor our own minimal Assembly Language. With such requirements given by the client:

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

The objective of handling a product that contains all these requirements in due time is achievable.

## Team Members

| **Photo** | **Name** | **Role** | **GitHub/LinkedIn** |
|---|---|---|---|
| <img src=https://ca.slack-edge.com/T06C726V31S-U06C4JC2XNE-g05a798d21f4-512>| MARLIER Thibaud | Project Manager | [GitHub](https://github.com/Biohazardyee) \| [LinkedIn](https://www.linkedin.com/in/thibaud-marlier/) |
| <img src=https://ca.slack-edge.com/T06C726V31S-U06CTC890F2-ga8f1bb3cfa4-512> | CLEMENT Quentin | Program Manager | [GitHub](https://github.com/Quentin-Clement) \| [LinkedIn](https://www.linkedin.com/in/quentin-clément-939110221/) |
| <img src=https://ca.slack-edge.com/T06C726V31S-U06C1LRUYJ1-g4a7908c1162-512> | FERNANDEZ Aurélien | Technical Leader | [GitHub](https://github.com/aurelienfernandez) \| [LinkedIn](https://www.linkedin.com/in/aurélien-fernandez-4971201b8/) |
| <img src=https://ca.slack-edge.com/T06C726V31S-U06C4FF7B7D-g01c4dd4777d-512> | ARCHIMBAUD Malo| Software Engineer | [GitHub](https://github.com/Malo-Archimbaud) \| [LinkedIn](https://www.linkedin.com/in/malo-archimbaud-58aa12232/) |
| <img src=https://ca.slack-edge.com/T06C726V31S-U06BQ2U1415-g9ecd879a69a-512> | KAKAL Mathis | Software Engineer | [GitHub](https://github.com/mathiskakal) \| [LinkedIn](https://www.linkedin.com/in/mathis-k-a239ba10a/) |
| <img src=https://ca.slack-edge.com/T06C726V31S-U06C4FFK53M-75d8750e33b8-512> | LEMOINE Arthur | Quality Assurance | [GitHub](https://github.com/arthur-lemo1ne) \| [LinkedIn](https://www.linkedin.com/in/arthur-lemoine-4b9782221/) |

## Stakeholders

| Role | Name |  Representative | Influence  | Expectations |
| :-: | :-: | :-: | :-:|  :-:|
| Client | ALGOSUP | Mr. JEANNIN Franck|The final product must comply to the requirements given by Mr. JEANNIN. Any major decision made by the team should be accepted by the client. The most importante intance in decision making. |The client expects a processor with an assembly language that does all the instructions that he asked us to provide. All while complying to the deadlines. |  

## Milestones

According to the Call For Tender given by the client, here are the milestones:

| Milestone | Due Date |
| :-: | :-: |
| Functional Specifications | 30 January 2024, 5pm |
| Technical Specifications | 9 February 2024, 5pm |
| Test Plan | 16 February 2024, 5pm |
| Final Product | 23 February 2024, 5pm |
| Final Presentation | 1 March 2024 |

**Expected milestones**:
| Milestone | Due Date |
| :-: | :-: |
| Project Charter | 22 January 2024, 5pm |
| Functional Specifications | 30 January 2024, 5pm |
| Technical Specifications | 9 February 2024, 5pm |
| Test Plan | 16 February 2024, 5pm |
| Final Product | 23 February 2024, 5pm |
| Final Presentation | 1 March 2024 |

## Deliverables

Based on the precedent tables here are what needs to be delivered to the client:  

- Project Charter,
- Functional specifications,
- Technical specifications,
- Test Plan,
- Final Products,
- Weekly Reports.

## Budget

There's no budget given by the client, nor set. This project will rely on the necessary free resources and software that are available to us. However, if a budget is necessary for the project, this will be discussed among with the stakeholders.
Having no budget could be a constraint if we find out that we have to buy any resource or software. This needs to be taken into account by our team.

## Risks And Assumptions


## Quality Standards

In this table, you will find the Minimum Viable Product (MVP).

| Aspect | Description|
| :-: | :-: |
| Storing an immediate value into  a register. | The user must be able to store a value into the memory of the CPU |
| Copying the value of a register into another register | The user should be able to sotre the value of a register into another register by making a copy of it.
| Reading the value of the memory at the address contained by a register and storing it into another register. | The processor should be able to handle reading value of the memory at a given address in a register and then store it into another register. |
| Storing the value of a register into memory at the address contained by another register. | The processor should handle the instruction to store the content of a register giving the address where the data will be stored.  |
| Comparing the content of registers. | Basic comparison of the value contained in a register. |
| Jumping unconditionally to a label. | Our processor should be able to jump without any condition to the beginning of a code block or to a specific instruction or function without taking into consideration the rest of the code. |
| Jumping conditionally to a label. | If a condition is met, our processor should be able to jump to a specific code block or instruction. Without taking into consideration the following of the code.|
| Calling a subroutine. | Our processor should be able to call a function when instructed to in order to satisfy the client's expectations. |
| Returning from a subroutine. | Once a subroutine is completed, our processor has to go back to the caller of the subroutine in order to continue the instructions that were given to it. |
| The 4 basic arithmetic operations: addition, subtraction, multiplication, and division. | Our processor and our   ssembly language should contain the four basic arithmetics operations, in order to make basic calculus. |
| The 4 basic logical operations: OR, AND, XOR, and NOT.| We have to be able to make binaries logical operation with our processor and our Assembly language.|
| Invent a minimal Asssembly language. |  We should create our own Assembly language which is compatible with our processor, which should give the instructions that our processor has to handle.|
| Create an interpreter for running Assembly code on that processor.  | We have to come up with our own interpreter that will directly interpret or execut the source code of our Assembly language.|
| The C program needs to check that the Assembly program is semantically valid and detects syntetical errors. | Before run time, our C program has to detect any errors that might interfer with the well-being of the hardware or that might make the program misbehave. |
| Create small "unit tests". | We have to create small programs using small assembly programs, that is similar to unit tests to prove that our program is working the way it is expected. |

These are the basic requirements that we given to us by the client in the Call For Tender, our team engages to fullfill these requirements in order to satisfy the client's expectation, if the final product doesn't meet these requirements, the contract with the client won't be fullfilled.

## Communication Plans

Communication in the team is handled via the platform Slack.  
Moreover, we have weekly meetings set, to discuss about the project's advancement. Get new ideas and improvde the overall quality of the final product.  
In addition, communication between the team and the stakeholder will be handled mostly by the Program manager and the Project manager.  
Our team will contact the client whenever it is needed and our team is always available to answer the client's question and consolate them if they have any worries.

## Success Criterias


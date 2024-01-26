# Risks and Mitigation plans - Virtual Processor - Team 3

| **Document Name**            | Risks and Mitigation plans |
| ---------------------------- | -------------------------- |
| **Document Owner**           | MARLIER Thibaud            |
| **Last Modification (Date)** | 01/25/2024                 |

# Introduction
This document will go through some of the risks that our team might encounter during the Virtual Processor Project.  
This project aims to design and create a virtual processor and an interpreter running our own Assembly language on that same processor. All developed by our team. Our product will be developed using the C language, relying only on the C standard library, no other libraries should be used by our team.
The project officially started (for the team) on the 17th of January. The final product will be given to the client the 23rd of February. In the short term, we have to come up with an original and new processor and Assembly language. We have to make our dream processor. The processor and Assembly will be aimed to be educative, meaning it should be understandable by everyone, and will help you during the process of learning how a CPU works.
We will draw inspiration from the architecture of the RISC-V 32-bit CPU architecture. Our Assembly language will be minimalistic, making each instruction as understandable and as clear as possible for the user. We will lessen the abstraction of multiple instructions, everything that demands too much knowledge or experience will be made easier to understand.  


## Risks and Mitigation

1. **Complexity:**
   - **Risk(s):** Designing a processor from scratch is a complex task, some features that we plan to implement might be hard and complex to be done.
   - **Mitigation:** Our team shouldn't rush into the development and ensure that what we want to implement isn't out of scope. Moreover, loads of research has to be done around the project to understand in deeper detail how a processor is built and works.

2. **Resource management (inside our processor):**
   - **Risk(s):** Managing resources like memory (RAM, ROM), registers, and cache can quite be a challenge. This can lead to performance issues, crashes, and unexpected behaviors.
   - **Mitigation:** We have to thoroughly plan the architecture of our processor and make sure that everything works effectively, memory management has to be as efficient as possible. This will be handled during the development process, checked by developers, then checked during quality assurance, to make sure that everything runs smoothly and as expected.

3. **Sudden Changes:**
    - **Risk(s):** Indeed, the client could change requirements at any time during the project. If the client wants to change anything, from the requirements to a specific architecture, whatever that has been specified or not in the Call For Tender or anything succeeding it.
    - **Mitigation:** We will comply with the client's expectations and requirements, so if needed after a change, we reserve ourselves the right to contact the client for any further information. Every consequence will be mitigated, changing the Work Breakdown Structure, management strategies, development strategies, and testing strategies, and documents will be reworked to comply with the client's needs. Our team will do everything possible to overcome sudden changes.

4. **Meeting Project Requirements:**
    - **Risk(s):** Failing to meet the specified criteria will lead to the project's rejection and will be considered a failure. Leading to subsequent consequences.
    - **Mitigation:** Ensure that we fully understand the project its requirements and constraints, client's needs... A load of work has to be done before starting development and production of the product. We will contact the client if any areas are still mystified. To make sure that we will meet every requirement for this project and come up with a project that is what the client expected.

5. **Limited Hardware Knowledge:**
    - **Risk(s):** Not having the necessary hardware knowledge of the computer architecture and hardware design principles, would lead to not making the optimal design choices and our product might end up being flowfull.
    - **Mitigation:** Reading lots of documentation on already existing processor architecture like CISC, ARM, RISC, and many others, to draw inspiration and learn about the architecture of a processor and/or the computer's architecture. To have an efficient product in the end.

6. **Documentation and code maintenance**
    - **Risk(s):** Ensuring the stability and efficiency of our product is paramount, and a key aspect of achieving this is maintaining comprehensive documentation on our processor architecture and assembly language. Without clear and thorough documentation, both our team and end-users may encounter difficulties in utilizing or maintaining the product, potentially resulting in instability and disruptions in functionality. Therefore, investing in robust documentation is essential to guarantee a smooth and seamless user experience, as well as to facilitate effective product maintenance.
    - **Mitigation:** Documentation will be done on our Processor architecture, our Assembly language, moreover these documents have to be as detailed and as clear as possible. Moreover, our developers will follow coding conventions that will be set and charted among us, so that the code is readable, maintainable and leading to higher product quality, making it easier to implement new functionality if needed, and making sure that everything is smooth and connected.

7. **Debugging and Testing:**
    - **Risk(s):** Debugging low-level programming languages can become challengeful. Moreover, we have to come up with our debugger built-in debugger. This task will be time-consuming for the software engineers as well as for the quality assurance. Moreover, we have to be sure that everything works as intended so testing everything will take lots of time to be done effectively.
    - **Mitigation:** Testing has to be done gradually, according to the project's development, beginning to test early on is necessary to remove problems as early as possible. Flattening the exhaustion of the necessary work needed to be done here over a wider period is also mandatory.

8. **Time Constraint:**
    - **Risk(s):** Learning the C language, the internal architecture of a CPU, defining all the tasks needing to be done, and then producing the final product is time-consuming, several weeks of research, learning, and setup will be needed for the well-being of the project, meaning that we are 'wasting' development time.
    - **Mitigation:** We have to start learning about various specificities as soon as possible and as efficiently as possible to not lose too much time. Moreover, the task being dispatched evenly and not exhaustively is necessary for the well-being of both the team and the project.

9. **Loss Of Human Resources:**
    - **Risk(s):** Team members may face setbacks, such as illness or transportation challenges, that hinder their ability to work effectively. Instances where team members are unable to work due to sickness or limited transportation options, such as unreliable train services, exemplify the difficulties in maintaining consistent presence and optimal productivity. These situations highlight the potential loss of work hours when a team member is unavailable due to unforeseen circumstances. Addressing these challenges requires implementing strategies to mitigate the impact of such disruptions and ensuring continuity in team collaboration and productivity.
    - **Mitigation:** Tasks could be attributed to another team member if needed so that we do not lose too much time and keep up to the pace that we desire.
  
10. **Hard Assembly**
    - **Risk(s):** Assembly being a low-level language is sometimes complicated to understand as there's some level of abstraction in the instructions names and what happens then in the bare metal level. Leading to a challenge to comprehend when you are relatively new to computer science and programming.
    - **Mitigation:** We want our product to be understandable by everyone. An 8-year-old kid, you, and even your grand parents have to be able to comprehend how the language works but also understand what's going on. To mitigate the risk of something being too hard to comprehend for newbies, we could test our product on a wide audience to be sure everything is clear and make changes if needed.

<br>
<br>
Here are some of the various risks that our team might encounter during the project. However, this document does not prevent every possible risk that could happen and isn't a hazard threshold, some events might still occur.

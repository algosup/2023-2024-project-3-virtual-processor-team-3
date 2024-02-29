# Want to explore our Assembler?

ALGORISK is an educational platform for learning about CPUs, assembly processes and RISC-V Architectures, from which we took inspiration.

In short, ALGORISK is broken down in two main components:
- ALGORASM: The Assembler for ALGORISK assembly language
- ALGOPROC: The virtual Processor for running the output machine language of ALGORASM

### Welcome to ALGORASM, ALGORISK's very own assembler!

To run it you must compile the program for your machine (run `make` while in ALGORASM directory)

Once compiled, a file named `gorasm` (short for ALGORASM) with no file extensions will pop up in that same directory.

You can then place it near your assembly files (in the same directory) and run `gorasm NAME_OF_YOUR_ASSEMBLY_FILE.gras.gras` and it will assemble the instructions into a machine language of the same name! (with the `.grml` extension, short for 'gorisk machine language'). If there are errors within your assembly code, errors will be returned to guide you through solving them.

You can read more on how to write assembly language for ALGORISK in our documentation section.

Once you have your `.grml` file, you can head over to ALGOPROC, ALGORISK's virtual processor, which you can run with `goproc NAME_OF_YOUR_FILE.grml`!

> [!TIP]
> Now, if you to skip those intermediate steps you can run the whole virtual processor along with its assembler together by running `gorisk NAME_OF_YOUR_ASSEMBLY_FILE.gras`

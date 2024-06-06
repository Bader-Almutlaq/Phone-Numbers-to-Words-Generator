# Word Generator Project

## Project Description

This C project generates words of a specified length (seven characters) where the characters '0' and '1' are not allowed. After generating the words, they are compared with entries in a `dictionary.txt` file. Only words that have meaning according to the dictionary are kept and written to an `output.txt` file. The words can be composite words (e.g., "THEBOSS", "FLOWERS").

## Features

- **Word Length**: All generated words are exactly seven characters long.
- **Character Restrictions**: The characters '0' and '1' are excluded from word generation.
- **Dictionary Validation**: Generated words are checked against `dictionary.txt` to ensure they have meanings.
- **Composite Words**: Composite words with meanings are also considered valid.

## Files

- `WordsGenerator.c`: The main source code file for the project.
- `Functions.c`: Contains all the functions used for generation and searching in the dictionary.
- `dictionary.txt`: A text file containing valid words for comparison.
- `output.txt`: A text file where valid generated words are stored.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- `dictionary.txt` file in the project directory with a list of valid words

### Building the Project

To compile the project, navigate to the project directory and use the following command:

```bash
gcc -o word_generator main.c
```

### Runing the project

To run the generator, navigate to the project directory and use the following command:
`./WordsGenerator.c`

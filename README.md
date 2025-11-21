# Push_swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations with the minimum number of moves.

## Table of Contents
- [Algorithm Overview](#algorithm-overview)
- [Operations](#operations)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Examples](#examples)

## Algorithm Overview

The sorting algorithm uses different strategies depending on the number of elements:

- **2 elements**: Simple swap if needed
- **3 elements**: Optimized sorting with direct operations
- **4 elements**: Push minimum to stack B, sort remaining 3, push back
- **5+ elements**: Complex algorithm using the Turk algorithm approach:
  1. Push the first two elements to stack B
  2. While stack A has more than 3 elements:
     - Calculate the cost to move each element to its target position in stack B
     - Move the cheapest element
  3. Sort the remaining 3 elements in stack A
  4. Push all elements back from stack B to stack A in the correct position
  5. Rotate stack A to have the minimum element at the top

### Key Features:
- **Cost Calculation**: Each element's move cost is calculated based on its position and target position
- **Target Finding**: Each element finds its optimal target position in the other stack
- **Median Optimization**: Determines whether to rotate up or down based on position
- **Cheapest First**: Always moves the element with the lowest cost first

## Operations

The following operations are available to manipulate the stacks:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the top element of stack B to stack A |
| `pb` | Push the top element of stack A to stack B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up (first element becomes last) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

## Installation

### Prerequisites
- GCC compiler
- Make

### Compilation

Clone the repository and compile the project:

```bash
git clone https://github.com/Auraa67/push_swap.git
cd push_swap
make
```

This will generate the `push_swap` executable.

### Clean Build Files

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything from scratch
```

## Usage

Run the program with a list of integers as arguments:

```bash
./push_swap [numbers...]
```

The program accepts integers in several formats:
- Multiple arguments: `./push_swap 3 2 1 5 4`
- Single quoted argument: `./push_swap "3 2 1 5 4"`

### Input Requirements:
- Only integers
- No duplicates
- Numbers within integer range

### Output:
The program outputs the sequence of operations needed to sort the numbers, one operation per line.

## Project Structure

```
push_swap/
├── Makefile                    # Build configuration
├── push_swap.h                 # Header file with function prototypes and structures
├── main.c                      # Entry point and initialization
├── push_swap.c                 # Main sorting logic and stack cleanup
├── init_stack.c                # Stack initialization
├── init_utils.c                # Initialization utilities
├── push_swap_utils.c           # General utility functions
├── check_condition.c           # Input validation
├── one_params_converter.c      # String to integer conversion
├── params_utils.c              # Parameter processing utilities
├── movement/                   # Stack operation implementations
│   ├── push_a.c               # Push to stack A
│   ├── push_b.c               # Push to stack B
│   ├── swap_a.c               # Swap stack A
│   ├── swap_b.c               # Swap stack B
│   ├── swap_ss.c              # Swap both stacks
│   ├── rotate_a.c             # Rotate stack A
│   ├── rotate_b.c             # Rotate stack B
│   ├── rotate_r.c             # Rotate both stacks
│   ├── reverse_rotate_a.c     # Reverse rotate stack A
│   ├── reverse_rotate_b.c     # Reverse rotate stack B
│   └── reverse_rotate_r.c     # Reverse rotate both stacks
└── sort_number/               # Sorting algorithm implementations
    ├── sort_min.c             # Sorting for 2-4 elements
    ├── sort_utils.c           # Sorting utilities
    ├── first_step.c           # First phase: A to B
    ├── second_step.c          # Second phase: B to A
    ├── second_step_utils.c    # Second phase utilities
    └── calculus.c             # Cost calculation functions
```

## Examples

### Example 1: Sort 3 numbers
```bash
$ ./push_swap 3 2 1
sa
rra
```

### Example 2: Sort 5 numbers
```bash
$ ./push_swap 5 4 3 2 1
pb
pb
sa
rra
pa
ra
pa
ra
```

### Example 3: Already sorted
```bash
$ ./push_swap 1 2 3 4 5
# No output - already sorted
```

### Example 4: Error handling
```bash
$ ./push_swap 1 2 abc
Error
```

```bash
$ ./push_swap 1 2 2
# No output - duplicate numbers
```

## Testing

To verify the program works correctly, you can count the number of operations:

```bash
# Count operations
./push_swap 3 2 1 | wc -l

# Test with random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

## Performance Guidelines

For reference, here are approximate operation counts for different input sizes:

- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations (good: < 900, excellent: < 700)
- 500 numbers: ≤ 5500 operations (good: < 7000, excellent: < 5500)

## Error Handling

The program handles various error cases:
- Invalid arguments (non-numeric)
- Duplicate numbers
- Numbers outside integer range
- Empty arguments
- Multiple signs (++ or --)

In case of error, the program prints `Error` to stderr and exits.

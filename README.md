*This project has been created as part of the 42 curriculum by segribas.*

# push_swap

A sorting algorithm project using two stacks and a limited set of operations.

## Description

push_swap sorts a list of integers using two stacks (a and b) and a fixed set of operations. The goal is to sort stack a in ascending order using the fewest operations possible.

Input is validated (digits only, no duplicates, within INT range), then sorted using small-sort for ≤5 elements or a chunked rank-based algorithm for larger inputs.

## Instructions

```bash
make
./push_swap 3 1 2
./push_swap "5 4 3 2 1"
```

### Data Structures

Two stacks — `a` and `b` — built from linked lists.

```c
t_node { int value; int rank; t_node *next; }
t_stack { t_node *top; int size; }
```

Each node holds its value, its rank (position in sorted order), and a pointer to the next node.

### Operations

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` | Swap top two elements of stack a / b |
| `ss` | Swap top two of both stacks |
| `pa` / `pb` | Push top of b to a / top of a to b |
| `ra` / `rb` | Rotate stack up (top goes to bottom) |
| `rr` | Rotate both stacks up |
| `rra` / `rrb` | Reverse rotate (bottom goes to top) |
| `rrr` | Reverse rotate both stacks |

### Input Validation

1. `is_digit` — checks every character is a valid digit (or sign)
2. `min_max_check` — checks every number is within INT range
3. `create_stack` — converts tokens to nodes
4. `duplicate_check` — no duplicate values allowed

### Sorting

| Size | Algorithm |
|------|-----------|
| 2 | `sort_two` — single `sa` |
| 3 | `sort_three` — bring max to bottom, fix top two |
| 4 | `sort_four` — push min to b, sort_three, push back |
| 5 | `sort_five` — push 2 smallest to b, sort_three, push back |
| 100+ | `k_sort1` + `k_sort2` |

### Chunked Sort (k_sort)

**k_sort1** — pushes elements from a to b in rank-order chunks:
- Elements with rank in current window → push to b
- Others → rotate a

**k_sort2** — pulls elements from b back to a:
- Find max in b, rotate b until max is on top, push to a
- Repeats until b is empty → a is sorted ascending

### Chunk sizes

- ≤ 100 elements: chunk size 20
- ≤ 500 elements: chunk size 29
- larger: `sqrt(size) * 1.4`

## Performance

| Input size | Max moves | Result |
|------------|-----------|--------|
| 3 | 3 | ✓ |
| 5 | 12 | ✓ |
| 100 | 700 | ~570 ✓ |
| 500 | 5500 | ~5100 ✓ |

## File Structure

| File | Content |
|------|---------|
| `push_swap.c` | `main` |
| `parse.c` | token creation and stack building |
| `validate.c` | input validation |
| `free.c` | memory cleanup |
| `ft_utils.c` | `ft_atol`, `ft_strlcpy` |
| `Split.c` | `ft_split` and helpers |
| `algo_utils.c` | `square_root`, `find_max`, `get_moves`, `get_chunk_size` |
| `stack_utils.c` | stack operations |
| `small_sort.c` | sort for 2-5 elements |
| `sort_stack.c` | sort dispatcher |
| `ksort.c` | `assign_ranks`, `k_sort1`, `k_sort2` |
| `swap_ops.c` | `sa`, `sb`, `ss` |
| `push_ops.c` | `pa`, `pb` |
| `rotate_ops.c` | `ra`, `rb`, `rr` |
| `rev_rotate_ops.c` | `rra`, `rrb`, `rrr` |

## Resources

- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) — overview of sorting concepts and complexity
- [Linked list data structure](https://en.wikipedia.org/wiki/Linked_list) — how linked lists work, used for both stacks
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) — push/pop semantics
- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — used to visualize and count operations during development
- Claude AI (claude.ai) — used for debugging memory leaks, explaining norminette errors, and understanding algorithm behavior. All code was written and understood by the author; AI was used as a reference and explainer, not as a code generator.

# minishell

A minimal shell implementation written in C as part of the 42 curriculum.

## Features

| Command | Description |
|---|---|
| `echo [args]` | Print arguments to stdout, supports `$VAR` expansion and quotes |
| `cd [dir]` | Change directory; supports `~`, `-`, `--`, `$HOME`, `$OLDPWD` |
| `pwd` | Print current working directory |
| `env` | Print all environment variables |
| `setenv [KEY] [VALUE]` | Set or update an environment variable |
| `exit` | Exit the shell |

## Build

```bash
make        # build
make re     # rebuild from scratch
make clean  # remove object files
make fclean # remove objects and binaries
```

## Usage

```bash
./minishell
```

The prompt displays the current directory name. Example session:

```
[ projects ][$➜] cd minishell
[ minishell ][$➜] pwd
/Users/mbaloyi/projects/minishell
[ minishell ][$➜] setenv FOO bar
[ minishell ][$➜] echo $FOO
bar
[ minishell ][$➜] exit
```

## Project Structure

```
minishell/
├── minishell.c     # Entry point, main loop, command dispatcher
├── ft_cd.c         # cd builtin
├── ft_echo.c       # echo builtin
├── ft_env.c        # env and variable lookup
├── ft_exit.c       # exit builtin
├── ft_setenv.c     # setenv builtin
├── ft_utils.c      # Shared utilities (ft_free_double, ft_input, etc.)
├── ft_sh.h         # Header — all declarations
├── libft/          # Custom libc (ft_strjoin, ft_strsplit, get_next_line, …)
└── Makefile
```

## Author

mbaloyi — ``WeThinkCode``

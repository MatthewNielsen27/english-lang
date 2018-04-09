# English

English is an experiment to create the highest-level programming language possible. English is written in english and compiled to c++.

## Sample syntax

### Console output

```txt
@main

write "hello world" to console
```

### Variables

```txt
@main

# Static-typed
create integer foo equal to 4
create integer bar equal to 0

set bar to equal foo

# Dynamic-typed
create variable name equal to "matthew"

put "hello, " to console
write name to console

```

### Loops

```txt
@main

create variable name equal to "matthew"

for x in name.length() interations do
  put name[x] to console
end
```

### Functions

```txt
@functions

function greet
  takes nothing
  returns nothing
does
  write "hello world" to console
end

@main

perform greet()
```

click [here](examples) to see more examples of .english programming

## Usage

Create hello.english source file

```txt
@main

write "hello world" to console
```

Then compile and run in the console

```console
$./english compile hello.english

$./english run hello.english
hello world
```

## Setup

Run the setup script

```console
./setup.sh
```

## Author(s)

* Matthew Nielsen
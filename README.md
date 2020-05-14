# AST Calculator

## Overview
An example of the AST based calculator built with flex and bison.

## Requirements

**Linux**

For the Ubuntu, you'll need the following dependencies:
```
sudo apt-get install g++ cmake flex bison
```

## Build

**Linux**

```
make
```

**Docker**

Alternatively you can use the `Dockerfile` from the repository.

```
docker build -t ast-calculator .
```

## Run

**Linux**

```
./build/ast_calc "386 + 7"
```

**Docker**

```
docker run --rm -it ast-calculator /bin/bash
./ast_calc "386 + 7"
```

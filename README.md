# CS258 — Data Structures in C++

All homework labs and in-class coding exercises for the term live in this repository.
You will clone it **once**, then push all of your work to **your own private repository**
for the rest of the term.

---

## Repository layout

```
labs/         Homework assignments  (lab01 … lab10, plus lab02a)
inclass/      In-class coding work  (class01 … class18)
```

Each assignment folder contains its own `README.md` with the specification and the
grading rubric. Most also contain starter code, a `Makefile`, and a `tests/`
directory with the Catch2 unit-testing header.

> **Do not modify any `Makefile` or anything inside a `tests/` directory** unless that
> assignment's README explicitly tells you to. Several assignments ask you to write your
> own Makefile and your own tests — those will say so.

---

## One-time setup

You only do this once, at the start of the term.

### 1. Clone this repository

```bash
git clone https://github.com/SOUComputerScience/cs258-assignments.git cs258
cd cs258
```

### 2. Create your own private repository

On GitHub, create a **new, empty, private** repository named:

```
cs258-<your-last-name>
```

Do **not** add a README, a `.gitignore`, or a license — it must be completely empty.

> Your repository **must be private**. A public repository containing your coursework
> is an academic-honesty problem for you and for whoever copies from it.

### 3. Point your clone at your repository

This makes your repo the default push target, and keeps mine available so you can
pull down fixes and new assignments later.

```bash
git remote rename origin upstream
git remote add origin https://github.com/<your-github-username>/cs258-<your-last-name>.git
git push -u origin main
```

Check that it looks right:

```bash
git remote -v
# origin    https://github.com/<you>/cs258-<lastname>.git  (fetch)
# origin    https://github.com/<you>/cs258-<lastname>.git  (push)
# upstream  https://github.com/SOUComputerScience/cs258-assignments.git  (fetch)
# upstream  https://github.com/SOUComputerScience/cs258-assignments.git  (push)
```

### 4. Give me access

On your repository: **Settings → Collaborators → Add people**, and add
**`<INSTRUCTOR-GITHUB-USERNAME>`**.

### 5. Submit your repository URL

Post the URL of your repository to the **"Repository URL"** assignment on Moodle.
I cannot grade work I cannot find, so this step is not optional.

---

## Working on an assignment

```bash
cd labs/lab03          # or inclass/class07, etc.
make                   # build and run the unit tests
```

Commit as you go — small, frequent commits with real messages are good practice and
they protect you from losing work:

```bash
make clean             # remove compiled binaries BEFORE committing
git add .
git commit -m "lab03: implement LinkedBag::remove"
git push
```

**Never commit compiled binaries.** Run `make clean` first. The `.gitignore` in this
repo catches most of them, but the surest way is `make clean`.

---

## Submitting

There is nothing to submit beyond pushing. When an assignment is due, I clone your
repository and grade whatever commit is the most recent one **before the deadline**.

So: **push before the deadline.** Work that is only on your laptop does not exist.

Verify your work actually arrived by opening your repository on GitHub in a browser
and looking at the files. Every term, someone commits all term and never pushes.

---

## Getting new assignments and fixes

When I add an assignment or correct a specification, pull it into your repository:

```bash
git pull upstream main
git push
```

If you have uncommitted changes, commit them first. If a pull produces a conflict in a
file *you* edited, that means I changed a file you also changed — resolve it, or ask me.

---

## Building and testing

Every assignment with tests uses [Catch2](https://github.com/catchorg/Catch2) (v2, single
header, already included — you do not need to install anything).

```bash
make            # typical: compile and run the tests
make test       # some assignments use this instead — check the README
make clean      # delete the compiled binaries
```

You need a C++ compiler with C++11 support (`g++` on Linux, `clang++` on macOS).
On the lab machines this is already installed.

---

## Getting help

- Read the assignment's own `README.md` first — the rubric is in there.
- Bring compiler errors to class or office hours. Paste the **first** error, not the last;
  C++ error cascades are usually one real mistake followed by fifty consequences.

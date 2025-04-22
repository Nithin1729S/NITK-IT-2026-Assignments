def grep(pattern, flags, files):
    output = ""

    if "who" in pattern:
        pattern+=" "
    for file in files:
        with open(file, 'r') as f:
            lines = f.readlines()
            for line_num, line in enumerate(lines, start=1):
                line = line.rstrip('\n')
                match = False

                if "-i" in flags:
                    pattern = pattern.lower()
                    line_lower = line.lower()
                else:
                    line_lower = line

                if "-x" in flags:
                    if line_lower == pattern:
                        match = True

                elif pattern in line_lower:
                    match = True

                if "-v" in flags:
                    match = not match

                if match:
                    if len(files)==1:
                        if "-l" in flags:
                            output += f"{file}\n"
                        elif "-n" in flags:
                            output += f"{line_num}:{line}\n"
                        else:
                            output += f"{line}\n"
                    else:
                        if "-l" in flags:
                            output += f"{file}\n"
                        elif "-n" in flags:
                            output += f"{file}:{line_num}:{line}\n"
                        else:
                            output += f"{file}:{line}\n"

    return output




print(grep("who", "-l", ["iliad.txt","midsummer-night.txt","paradise-lost.txt"]))

print(grep("who", "-n -l", ["iliad.txt","midsummer-night.txt","paradise-lost.txt"]))





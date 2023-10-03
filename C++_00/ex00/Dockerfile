# Use an official Linux image as a parent image
FROM ubuntu:20.04

# Install necessary packages
RUN apt-get update && \
    apt-get install -y g++ && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /app

# Copy your C++ source code into the container
COPY . /app

# Compile your C++ code
RUN g++ -o megaphone megaphone.cpp

# Specify the command to run when the container starts
CMD ["./megaphone"]

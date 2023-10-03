# Use an official Linux image as a parent image
FROM ubuntu:20.04

# Install necessary packages
RUN apt-get update && \
    apt-get install -y g++ make && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /app

# Copy your C++ source code and Makefile into the container
COPY . /app

# Build your C++ program using the Makefile
RUN make

# Specify the command to run when the container starts
CMD ["./account"]



# Commands are as follow
# docker build -t <image_name> .
# docker run -it --rm <image_name>

# To pass arguments
# docker run -it --rm <image_name> <program_name> <arguments>



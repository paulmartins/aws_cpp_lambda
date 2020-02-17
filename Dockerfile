FROM amazonlinux:latest

## install required development packages
RUN yum -y groupinstall "Development tools" 
RUN yum -y install gcc-c++ libcurl-devel cmake3 git
RUN pip3 install awscli

# install C++ runtime environment
RUN git clone https://github.com/awslabs/aws-lambda-cpp.git && \
    cd aws-lambda-cpp && mkdir build && cd /aws-lambda-cpp/build && \
    cmake3 .. -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF \
    -DCMAKE_INSTALL_PREFIX=/out -DCMAKE_CXX_COMPILER=g++ && \
    make && make install

# Pre-Req Repos
RUN yum install boost-devel -y

# Copy files for tutorials
COPY ./cpp_tuto ./cpp_tuto
COPY ./boost_tuto ./boost_tuto

# Define working directory
# WORKDIR "/cpp_tuto"

# include C++ source code and build configuration
# ADD adaptiveUpdate.cpp /adaptiveUpdate
# ADD CMakeLists.txt /adaptiveUpdate
# C++ runtime for AWS lambda

## Docker

To build the docker image, run the following in the repo root dir.

```
docker build . -t aws_cpp_docker
```

To pull the image from dockerhub, run

```

```

To push the image to dockerhub, run

```
docker push ppjmartins/lambda_cpp_boost:latest
```


## C++ Tutorial

Jump inside the container and attached a volume so we can interact with it

```
docker run --rm -ti --name=aws_cpp_docker  -v $PWD/cpp_tuto:/cpp_tuto aws_cpp_docker /bin/bash
```

1. 

## Boost Graph Introduction

FROM gcc:latest as build

WORKDIR /gtest_build

RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-dev \
      cmake \
    && \
    cmake -DCMAKE_BUILD_TYPE=Release /usr/src/gtest && \
    cmake --build . && \
    mv lib/*.a /usr/lib

ADD ./app /app/src

WORKDIR /app/build

RUN cmake ../src && \
    cmake --build . && \
    CTEST_OUTPUT_ON_FAILURE=TRUE cmake --build . --target test

FROM ubuntu:latest

RUN groupadd -r alisa && useradd -r -g alisa alisa
USER alisa

WORKDIR /app

COPY --from=build /app/build/testproj .

ENTRYPOINT ["./testproj"]

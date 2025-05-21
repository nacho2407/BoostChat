# BoostChat-server

BoostChat의 서버 프로그램입니다. `boost_chat::Server`에서 새로운 클라이언트를 받아 새로운 `boost_chat::Session`에 할당시켜 처리합니다. 클라이언트와는 `boost_chat::Message` 형식으로 통신하며, 통신의 주요 이벤트들은 `boost_chat::Logger`를 통해 서버에 기록됩니다.


## main

BoostChat-server의 메인 프로그램으로, 서버를 실행할 포트를 설정하고, `boost_chat::Server` 인스턴스를 생성하여 비동기 이벤트 루프를 실행합니다.


### 구성 파일

- `main.cpp`: BoostChat-server 진입점


### 기본 실행 흐름

1. 설정된 기본 포트 번호 또는 명령줄 인자를 통해 포트 번호 설정

2. `boost_asio::Server` 인스턴스 생성

3. `boost::asio::io_context`를 통해 비동기 이벤트 루프 실행


### 주요 상수 / 매크로

| 상수 / 매크로 | 설명 |
|---------------|------|
| `BOOST_CHAT_SERVER_VERSION` | BoostChat-server 버전 |
| `BOOST_CHAT_DEFAULT_PORT` | 기본 포트 번호 |


### 함수

#### `int main(int argc, char* argv[])`

- BoostChat-server의 진입점

- 명령줄 인자로 받은 포트 번호를 파싱

    - 인자가 없는 경우 기본 포트 번호 이용

- BoostChat-server 버전 출력

- `run_server(port)` 호출


#### `static int run_server(const unsigned short port)`

- `boost::asio::io_context` 생성

- `boost_chat::Server`를 생성하며 인자로 받은 포트 번호를 바인딩

- `context.run()`을 통해 비동기 이벤트 루프 실행


### 의존 라이브러리

- [Boost.Asio](https://www.boost.org/library/latest/asio/)


*추가 예정*

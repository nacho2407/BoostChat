# BoostChat-server

## app/main

BoostChat-server의 진입점으로, 서버를 실행할 포트를 설정하고, `boost_chat::Server` 인스턴스를 생성하여 비동기 이벤트 루프를 실행합니다.


### 구성 파일

- `main.cpp`: BoostChat-server 진입점


### 기본 실행 흐름

1. 기본 포트(24072) 또는 커맨드라인 인자를 통해 포트 설정

2. `boost_asio::Server` 인스턴스 생성

3. `boost::asio::io_context`를 통해 비동기 이벤트 루프 실행

### 주요 상수 / 매크로

| 상수 / 매크로 | 설명 |
|---------------|------|
| `BOOST_CHAT_SERVER_VERSION` | BoostChat-server 버전 |
| `BOOST_CHAT_DEFAULT_PORT` | 기본 포트 번호(24072) |

*추가 예정*

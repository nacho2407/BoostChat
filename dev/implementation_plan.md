# 구현 계획

## 클라이언트 구조

- `app/main.cpp`: 프로그램 진입점

- `lib/client.cpp`, `lib/client.hpp`: 통신 및 메시지 송수신

- `lib/controller.cpp`, `lib/controller.hpp`: 입력 처리, 화면 처리 로직

- `lib/def.hpp`: 공통 상수, 버퍼 사이즈 등

- `lib/message.hpp`: 서버와 주고 받을 메세지 형식

- `lib/ui.cpp`, `lib/ui.hpp`: ncurses 기반 UI


## 구현 순서

- 서버 테스트

- `lib/client.cpp`, `lib/client.hpp`: `boost::asio::tcp::socket` 기반 클라이언트 클래스

- `lib/ui.cpp`, `lib/ui.hpp`: UI 프레임

- `app/main.cpp`: 서버 연결 + UI 초기화 + 입력 루프

- `lib/controller.cpp`, `lib/controller.hpp`: 키 입력 받아 메시지 전송

- 수신 메시지를 UI에 출력

- 디버깅

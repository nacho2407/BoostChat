# To-do List

- `boost_chat::Message` 검토

- `boost_chat::Server`, `boost_chat::Session` 재작성

    - 클라이언트와 통신할 때 항상 `boost_chat::Message` 형식으로 통신하되, 통신 시 `boost_chat::Message`의 크기를 우선 문자열로 받아(`boost::asio::tcp::socket::async_read_until`, `\n`으로 구분) 서버가 확인 후 준비가 되었음을 알리면 클라이언트가 `boost_chat::Message` 형식의 메시지를 전송하는 것으로 구현

- BoostChat-server 테스트

- `implementation_plan.md` 수정

- BoostChat-server 문서화

- 클라이언트 구현

# Smart Rescue Helmet

**Smart Rescue Helmet** là dự án mũ bảo hiểm thông minh tích hợp IoT, được thiết kế để phát hiện tai nạn, cảnh báo nồng độ cồn và hỗ trợ định vị khẩn cấp cho người tham gia giao thông. Hệ thống sử dụng Arduino kết hợp với các cảm biến và module liên lạc để gửi thông báo tự động đến người thân khi có sự cố xảy ra.

## Tính năng nổi bật

* Phát hiện tai nạn (Fall Detection): Tự động phát hiện khi người dùng bị ngã xe (dựa trên góc nghiêng > 70 độ).
* Cảnh báo nồng độ cồn: Tích hợp cảm biến khí gas để phát hiện nồng độ cồn trong hơi thở người lái, gửi cảnh báo nếu vượt mức cho phép.
* Nút khẩn cấp (SOS Button): Người dùng có thể chủ động bấm nút để gọi điện/nhắn tin cầu cứu khi gặp cướp giật hoặc nguy hiểm khác.
* Định vị GPS: Tự động gửi tin nhắn chứa tọa độ (link Google Maps) đến số điện thoại người thân khi có sự cố.
* Giám sát từ xa: Người thân có thể gọi điện vào số SIM trên mũ để nhận tin nhắn trả về vị trí hiện tại của người đội.
* Phát hiện đội mũ: Cảm biến hồng ngoại giúp hệ thống chỉ kích hoạt các tính năng cảnh báo khi người dùng thực sự đội mũ lên đầu (tiết kiệm pin và tránh báo giả).

## Phần cứng yêu cầu

Dự án sử dụng các linh kiện chính sau:

1.  Vi điều khiển: Arduino Nano (hoặc Arduino Pro Mini).
2.  Module Sim/GPS: A9G (GPRS/GSM+GPS/BDS) để nghe gọi, nhắn tin và định vị.
3.  Cảm biến gia tốc: MPU6050 (Đo góc nghiêng để phát hiện ngã).
4.  Cảm biến nồng độ cồn: MQ-3.
5.  Cảm biến vật cản: HW-488 (Hồng ngoại) để phát hiện trạng thái đội mũ.
6.  Nguồn Pin Li-Po 1000mAh và mạch sạc.
7.  Khác: Còi chíp (Buzzer), nút nhấn, công tắc, dây nối.

## Sơ đồ kết nối (Pinout)

Kết nối các module với Arduino Nano như sau (Tham khảo sơ đồ nguyên lý):

### 1. MPU6050 (Giao tiếp I2C)
* **VCC:** 5V
* **GND:** GND
* **SCL:** A5
* **SDA:** A4

### 2. Module A9G
* VCC: 5V (Yêu cầu nguồn dòng đủ lớn)
* GND: GND
* TX: Nối với chân RX của Arduino (hoặc chân Digital mềm được quy định)
* RX: Nối với chân TX của Arduino

### 3. Cảm biến MQ-3
* **VCC:** 5V
* **GND:** GND
* **A0 (Analog Output):** A0 (hoặc chân Analog khác tùy code)

### 4. Cảm biến Hồng ngoại (HW-488)
* **OUT:** D4 (Chân Digital 4 - kích hoạt hệ thống)

## Nguyên lý hoạt động

1.  Kích hoạt: Hệ thống chỉ hoạt động khi cảm biến hồng ngoại phát hiện khoảng cách < 2cm (đang đội mũ).
2.  Phát hiện ngã:
    * Nếu cảm biến MPU6050 đo được góc nghiêng > 70 độ và duy trì trong 5 giây -> Hệ thống hiểu là đã bị ngã.
    * Còi báo động sẽ kêu. Sau 10 giây cảnh báo âm thanh, nếu người dùng không tắt báo động bằng nút nhấn, hệ thống sẽ kích hoạt gọi điện và gửi SMS tọa độ.
3.  Cảnh báo rượu bia:
    * Nếu MQ-3 phát hiện nồng độ cồn vượt ngưỡng -> Gửi SMS cảnh báo cho người thân *"Người nhà của bạn bị say rượu..."*.
4.  Định vị chủ động:
    * Khi số điện thoại của người thân (đã được lập trình trước) gọi đến SIM trên mũ, hệ thống sẽ tự động ngắt máy và gửi lại tin nhắn chứa tọa độ GPS.

## Hướng dẫn sử dụng

1.  Nạp code vào Arduino Nano (sử dụng Arduino IDE).
2.  Lắp thẻ SIM (có đăng ký mạng) vào module A9G.
3.  Khởi động nguồn mũ bảo hiểm.
4.  Đội mũ lên đầu để hệ thống bắt đầu giám sát.
5.  **Lưu ý:** Cần hiệu chỉnh độ nhạy của cảm biến MQ-3 và MPU6050 cho phù hợp với thực tế.

## Tác giả

Dự án được thực hiện bởi học sinh trường THPT Phan Bội Châu.
Tài liệu tham khảo: `011_BÁO CÁO.pdf`

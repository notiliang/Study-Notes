# 类名
QserialPort
# 方法
## error() const  
###  权限  
 public
###  返回值
 类型----->QSerialPort::SerialPortError  
 

|`QSerialPort::NoError`|`0`|No error occurred.|
|`QSerialPort::DeviceNotFoundError`|`1`|An error occurred while attempting to open an non-existing device.|
|`QSerialPort::PermissionError`|`2`|An error occurred while attempting to open an already opened device by another process or a user not having enough permission and credentials to open.|
|`QSerialPort::OpenError`|`3`|An error occurred while attempting to open an already opened device in this object.|
|`QSerialPort::NotOpenError`|`13`|This error occurs when an operation is executed that can only be successfully performed if the device is open. This value was introduced in [QtSerialPort](https://doc.qt.io/qt-5/qtserialport-module.html) 5.2.|
|`QSerialPort::ParityError`|`4`|Parity error detected by the hardware while reading data. This value is obsolete. We strongly advise against using it in new code.|
|`QSerialPort::FramingError`|`5`|Framing error detected by the hardware while reading data. This value is obsolete. We strongly advise against using it in new code.|
|`QSerialPort::BreakConditionError`|`6`|Break condition detected by the hardware on the input line. This value is obsolete. We strongly advise against using it in new code.|
|`QSerialPort::WriteError`|`7`|An I/O error occurred while writing the data.|
|`QSerialPort::ReadError`|`8`|An I/O error occurred while reading the data.|
|`QSerialPort::ResourceError`|`9`|An I/O error occurred when a resource becomes unavailable, e.g. when the device is unexpectedly removed from the system.|
|`QSerialPort::UnsupportedOperationError`|`10`|The requested device operation is not supported or prohibited by the running operating system.|
|`QSerialPort::TimeoutError`|`12`|A timeout error occurred. This value was introduced in [QtSerialPort](https://doc.qt.io/qt-5/qtserialport-module.html) 5.2.|
|`QSerialPort::UnknownError`|`11`|An unidentified error occurred.|
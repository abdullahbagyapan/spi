# SPI (Serial Peripheral Interface) Communication Between Two Arduino's

This project walks you through the process building an AVR application to exercise the **SPI** and **UART** on the **ATmega328p microcontroller**.

## Prerequisites

We need to install **library**, **compiler**, **binary to hex converter**, and **AVR MCU programmer**

These applications can be install by following line:

```bash
sudo apt install avr-libc avrdude binutils-avr gcc-avr
```

## The Code

### Master

The code below initializes the **SPI module as master** and prepare that for use. The while loop **transmit message** using SPI.

```c++
int main(void) {

    SPI_MasterInit();


    while (1) {

        SPI_PutString("Hello World !\r\n");

    }

    return 0;
}
```

### Slave

The code below initializes the **UART and SPI module** and prepare them for use. The while loop **receive message** from SPI and **transmit it** by UART.

```c++
int main(void) {

    SPI_SlaveInit();
    UART_Init();

    while (1) {

        uint8_t ui8Data = SPI_GetChar();
        
        UART_PutChar(ui8Data);
        
    }

    return 0;
}
```


## Compiling The Code

To compile the source code we need to create a Makefile to automate the process. Makefiles allow us to place all build/clean/flash commands into one easy to use file. Each microcontroller has a unique set of parameters prior to compiling and deploying. These commands are listed a the top of the Makefile and are easily changed.

Now that your Makefile is complete issue the make from the command start the build process.

### Master

```console
make -f Makefile-master
```

### Slave

```console
make -f Makefile-slave
```

## Flashing The Code

Now that we compiled the code we can deploy to our microcontroller.

### Master

```console
make -f Makefile-master flash
```

### Slave

```console
make -f Makefile-slave flash
```
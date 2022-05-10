#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc,char**argv)

{
	int fd ;
	
	if(argc != 2)
	{
		printf("Usage error:<a.out>\n");
		exit(EXIT_FAILURE);
	}

	 fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	  	 
	char buf[8192] = {} ;

       int count  = read(fd,buf,8192);

	if(count < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	
	
	unsigned char e_ident[16];
	memcpy(e_ident , buf , 16);

	//magic number 
	
	//check for bad file
	
	/*if(e_ident[0x01] !=  )
	{
		printf("readelf: Error: Not an ELF file - it has the wrong magic bytes at the start\n");

		exit(EXIT_FAILURE);
	}*/
	
	printf("Magic:    %hhx %hhx %hhx %hhx\n",e_ident[0x00],e_ident[0x01],e_ident[0x02],e_ident[0x03]);
	
	
	//Class
	 
	 printf("Class:                                                   ");
	if(e_ident[0x04] == 1)
	{
		printf("  ELF32\n");
	
	}
	else if(e_ident[0x04] == 2)
		printf(" ELF64\n");

	//Data
	
	printf("Data:                                                      ");

	if(e_ident[0x05] == 1)
		printf(" 2's complement, little endian\n");
	else if(e_ident[0x05] == 2)
		printf(" 2's complement, big endian\n");


	//version
	
	if(e_ident[0x06] == 1)
		printf("Version:                                          1 (current)\n");
	else
		printf("version not found\n");

	//os/ABI
	
	printf("OS/ABI:               ");

	switch(e_ident[0x07])
	{
		case 0:
			printf("UNIX - system v \n");
			break;
		case 1:
			printf("HP-UX\n");
			break;
		case 2:
			printf("NetBSD\n");
			break;
		case 3:
			printf("Linux\n");
			break;
		case 4:
			printf("GNU Hurd\n");
			break;
		case 5:
			printf("Solaris\n");
			break;
		case 6:
			printf("AIX\n");
			break;
		case 7:
			printf("FreeBSD\n");
			break;
		case 8:
			printf("Tru64\n");
			break;
		case 9:
			printf("Novell Modesto\n");
			break;
		case 'A':
			printf("OpenBSD\n");
			break;
		case 'B':
			printf("OpenVMS\n");
			break;
		case 'C':
			printf("NonStop Kernel\n");
			break;
		case 'D':
			printf("AROS\n");
			break;
		case 'E':
			printf("Fenix Os\n");
			break;
		case 'F':
			printf("CloudABI\n");
			break;
		case 10:
			printf("Stratus Technologies OpenVOS\n");
			break;


	}


	//abi version
	
	printf("ABI Version:                %hhx\n",e_ident[0x08]);


		//e_type


	uint16_t e_type = *(uint16_t*) &buf[0x10];
	printf("Type:                                                   ");
	switch(e_type)
	{
		case 0x00:
			printf("NONE (unknown type)\n");
			break;
		case 0x01:
			printf("REL (relocatable file)\n");
			break;
		case 0x02:
			printf("EXEC (executable file)\n");
			break;
		case 0x03:
			printf("DYN (shared object file)\n");
			break;
		case 0x04:
			printf("CORE (core file)\n");
			break;
		case 0xFE00:
			printf("OS specific\n");
			break;
	 	case 0xFEFF:
			printf("OS specific\n");
			break;
	  	case 0xFF00:
			printf("Processor specific\n");
			break;
		case 0xFFFF:
			printf("Processor specific\n");
			break;
		}


	short int e_machine = *(short int*)&buf[0x12];


	printf("machine is :                               ");

	switch(e_machine)
	{
		case 0x00:
			printf("unknown\n");
			break;
		case 0x01:
			printf("AT&T WE 32100\n");
			break;
		case 0x02:
			printf("SPARC\n");
			break;
		case 0x03:
			printf("x86\n");
			break;
		case 0x04:
			printf("Motorola 68000 (M68k)\n");
			break;

		case 0x05:
			printf("Motorola 68000 (M88k)\n");
			break;
		case 0x06:
			printf("Intel MCU\n");
			break;
		case 0x07:
			printf("Intel 80860\n");
			break;
		case 0x08:
			printf("MIPS\n");
			break;
		case 0x09:
			printf("IBM_System/370");
			break;

		case 0x0A:

			printf("MIPS RS3000 Little-endian\n");
			break;

		case 0x0B-0x0D:
			printf("Reserved for future use\n");
			break;
		case 0x0E:
			printf("Hewlett-Packard PA-RISC\n");
			break;
		case 0x0F:
			printf("Reserved for future use\n");
			break;
		case 0x13:
			printf("Intel 80960\n");
			break;
		case 0x14:
			printf("PowerPC \n");
			break;
		case 0x15:
			printf("PowerPC (64-bit)\n");
			break;
		case 0x16:
			printf("S390, including S390\n");
			break;
		case 0x17:
			printf("IBM SPU/SPC\n");
			break;
		case 0x18-0x23:
			printf("Reaserved for future use\n");
			break;
		case 0x24:
			printf("NEC V800\n");
			break;
		case 0x25:
			printf("Fujitsu FR20\n");
			break;
		case 0x26:
			printf("TRW RH-32\n");
			break;
		case 0x27:
			printf("Motorola RCE\n");
			break;
		case 0x28:
			printf("ARM (up to ARMv7/Aarch32)\n");
			break;
		case 0x29:
			printf("Digital Alpha\n");
			break;
		case 0x2A:
			printf("SuperH\n");
			break;
		case 0x2B:
			printf("SPARC Version 9\n");
			break;
		case 0x2C:
			printf("Siemens TriCore embedded processor\n");
			break;
		case 0x2D:
			printf("Argonaut RISC Core\n");
			break;
		case 0x2E:
			printf("Hitachi H8/300\n");
			break;
		case 0x2F:
			printf("Hitachi H8/300H\n");
			break;
		case 0x30:
			printf("Hitachi H8S\n");
			break;
		case 0x31:
			printf("Hitachi H8/500\n");
			break;
		case 0x32:
			printf("IA-64\n");
			break;
		
		case 0x33:
			printf("Stanford MIPS-X\n");
			break;
		case 0x34:
			printf("Motorola ColdFire\n");
			break;
		case 0x35:
			printf("Motorola M68HC12\n");
			break;
		case 0x36:
			printf("Fujitsu MMA Multimedia Accelerator\n");
			break;
		case 0x37:
			printf("Siemens PCP\n");
			break;
		case 0x38:
			printf("Sony nCPU embedded RISC processor\n");
			break;
		case 0x39:
			printf("Denso NDR1 microprocessor\n");
			break;
		case 0x3A:
			printf("Motorola Star*Core processor\n");
			break;
		case 0x3B:
			printf("Toyota ME16 processor\n");
			break;
		case 0x3C:
			printf("STMicroelectronics ST100 processor\n");
			break;
		case 0x3D:
			printf("Advanced Logic Corp. TinyJ embedded processor family\n");
			break;
		case 0x3E:
			printf("AMD x86-64\n");
			break;
		case 0x8C:
			printf("TMS320C6000 Family\n");
			break;
			
		case 0xAF:
			printf("MCST Elbrus e2k\n");
			break;
		case 0xB7:
			printf("ARM 64-bits (ARMv8/Aarch64)\n");
			break;
		case 0xF3:
			printf("RISC-V\n");
			break;
		case 0xF7:
			printf("Berkeley Packet Filter\n");
			break;
		case 0x101:
			printf("WDC 65C816\n");
			break;

	}

	//version
	
	int e_version = *(int*) &buf[0x14];

	printf("Version:                 0x%d\n",e_version);


	//entry point address
	
	long int e_entry = *(long int*) &buf[0x18];
	printf("Entry point :                 0x%lx  \n",e_entry);

	//start of program  headers              
	
	long int e_phoff = *(long int*) &buf[0x20];

	printf("Start of program header:        %ld (bytes into file)\n",e_phoff);
	
	//start of section headers
	
	long int e_shoff = *(long int*) &buf[0x28];

	printf("Size of section headers:        %ld (bytes into file)\n",e_shoff);
	
	//flags
	
	int e_flags = *(int*) &buf[0x30];

	printf("Flags:                         0x%x\n",e_flags);

	//size of this header 
	
	short  int e_ehsize = *(short int*) &buf[0x34];

	printf("Size of this headers:            %d (bytes) \n ",e_ehsize);

	//size of program headers

	short int e_phentsize = *(int *) &buf[0x36];

	printf("size of program headers:         %d (bytes)\n",e_phentsize);

	//Number of program headers 
	
	short int e_phnum = *(short int*) &buf[0x38];

	printf("Number of program headers:        %d\n",e_phnum);

	//Size of section headers 
	
	short int e_shentsize = *(short int*) &buf[0x3A];

	printf("Size of section headers:          %d (bytes)\n",e_shentsize);

	//Number of section headers 
	
	short int e_shnum = *(short int *) &buf[0x3C];

	printf("Number of section headers:        %d\n", e_shnum);

	//section header string table index 
	

	short int e_shstrndx = *(short int*) &buf[0x3E];

	printf("Section header string table index: %d\n",e_shstrndx);


	//program headersd
	
}


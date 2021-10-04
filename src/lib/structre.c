#include <stdio.h>
#include <stdlib.h>


typedef struct person {
	char name[21];
	char sername[21];
	int height;
} person;

void output(person* data, int n);
void read_str(char* str);
void read_person(person* data, int x);
void read(person* data, int n);

int main() {
	int n = 3;
	person data[n];
	read(data, n);
	output(data, n);
	return 0;
}

void read_str(char* str) {
	char temp;
	int x = 0;
	while (x < 20) {
		temp = getchar();
		if (temp == '\n')
			break;
		*(str + x) = temp;
		x += 1;
	}
	*(str + x) = '\0';
}

void read_person(person* data, int x) {
	read_str(data[0].name);
	read_str(data[0].sername);
	data[0].height = 100 * x + 50;
}

void read(person* data, int n) {
	int x = 0;

	while (x < n) {
		read_person(data + x, x);
		x += 1;
	}
}

void output(person* data, int n) {
	int x = 0;

	while (x < n) {
		if (data[x].height > 100)
			printf("%s %s %d, ", (data + x)->name, (data + x)->sername, (data + x)->height);
		x += 1;
	}
}

// имя фамилия рост

/* typedef struct person {
    char name[21];
    char sername[21];
    int height;
} person;

void output(person *data, int n);
void read_str(char *str);
void read_person(person *data, int x);
void read(person *data, int n);

int maim() {
    int personCount = 0;
    char c;
    if ((scanf("%d%c", &personCount, &c) == 2) && (c == '\n') && (personCount != 0)) {
        person data[personCount];
        read(data, personCount);

    } else {
        printf("n/a");
        exit(1);
    }
    return 0;
}

void read_str(char *str) {
    char tmp;
    int count = 0;
    while (count < 20) {
        tmp = getchar();
        if (tmp == '\n') {
            break;
        }
        *(str + count) = tmp;
        count += 1;
    }
    str[count] = '\0';
}

void read_person(person *data, int x) {
    read_str(data[0].name);
    read_str(data[0].sername);
    data[0].height = 100 * x + 50;
}

void read(person *data, int personCount) {
    int tmpCount = 0;
    while(tmpCount < personCount) {
        read_person(data + tmpCount, tmpCount);
        tmpCount += 1;
    }
}

void output(person *data, int n) {
    int x = 0;

    if (data[x].height > 100) {
        printf("%s %s %d, ", (data +x)->name, (data + x)->sername, (data + x)->height);
    }
    x +=1;
} */
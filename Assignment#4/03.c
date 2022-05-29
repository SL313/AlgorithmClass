#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct knapsack {
	int item;
	int weight;
	int value;
}item;

item num[6];


void sorting(){
	item tmp;
	for (int i = 0; i < 5; i++) {
		int temp = i;
		for (int j = i + 1; j < 6; j++) {
			if ((num[temp].value / num[temp].weight) <= num[j].value / num[j].weight) temp = j;
		}
		tmp = num[temp];
		num[temp] = num[i];
		num[i] = tmp;
	}
}

int main(void) {
	int resultValue = 0, resultWeight = 0;
	int resultitem[6];
	num[0].item = 1;
	num[0].weight = 6;
	num[0].value = 60;
	num[1].item = 2;
	num[1].weight = 10;
	num[1].value = 20;
	num[2].item = 3;
	num[2].weight = 3;
	num[2].value = 12;
	num[3].item = 4;
	num[3].weight = 5;
	num[3].value = 80;
	num[4].item = 5;
	num[4].weight = 1;
	num[4].value = 30;
	num[5].item = 6;
	num[5].weight = 3;
	num[5].value = 60;
	sorting();

	int i = 0;
	while (1) {
		resultWeight += num[i].weight;
		resultValue += num[i].value;
		resultitem[i] = num[i].item;

		printf("index: %d, the fraction number: 1\n", num[i].item);
		i++;
		if (resultWeight == 16) {
			printf("the maximum value: %d", resultValue);
			break;
		}
		else if (resultWeight + num[i].weight > 16) {
			resultValue += num[i].value / num[i].weight * (16 - resultWeight);
			printf("index: %d, the fraction number: %f\n", num[i].item, (double)(16 - resultWeight) / num[i].weight);
			printf("\nthe maximum value: %d", resultValue);
			break;
		}
	} 
	return 0;
}

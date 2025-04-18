#include <stdio.h>
#define SUBJECTS 3
const char *subject_names[] = { "英語", "数学", "国語" };

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	int students;
	printf("受験者数を入力！\n");
	scanf("%d", &students);

	int scores[SUBJECTS][students];
	int i, j;

	// 各科目の点数を入力
	for (i = 0; i < SUBJECTS; i++) {
		printf("%sの点数を受験番号順に入力！\n", subject_names[i]);
		for (j = 0; j < students; j++) {
			printf("受験番号%d\t", j + 1);
			scanf("%d", &scores[i][j]);
		}
	}

	// 各受験者の成績・平均を表示
	int student_sum;
	for (j = 0; j < students; j++) {
		printf("\n受験番号%dの人の成績\n", j + 1);
		student_sum = 0;
		for (i = 0; i < SUBJECTS; i++) {
			printf("%s:%d点\t", subject_names[i], scores[i][j]);
			student_sum += scores[i][j];
		}

		printf("平均:%d点\n", student_sum / SUBJECTS);
	}

	// 各教科の平均点と全体平均
	int subject_sum, subject_avg;
	int total_sum = 0;
	printf("\n受験者の平均点\n");
	for (i = 0; i < SUBJECTS; i++) {
		subject_sum = 0;
		for (j = 0; j < students; j++) {
			subject_sum += scores[i][j];
		}
		subject_avg = subject_sum / students;
		total_sum += subject_avg;
		printf("%s:%d点\t", subject_names[i], subject_avg);
	}
	printf("全体:%d点\n", total_sum / SUBJECTS);

	return 0;
}

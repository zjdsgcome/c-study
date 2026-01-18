#include "文件操作.h";
//fgets读取文件
static void fgets_file() {
	FILE* fp = NULL;

	fp = fopen(FILE_URL, "r");

	if (fp == NULL) {
		perror("open file error");
		return;
	}

	while (1) {//因为文件读取到换行符即结束，因此循环读取
		char buf[1000] = { 0 };

		char* read = fgets(buf, 1000, fp);

		if (read == NULL) {
			if (feof(fp)) {
				printf("已读取到文件末尾（EOF）\n");
			}
			else if (ferror(fp)) {
				printf("文件读取出错");
			}

			break;
		}

		printf("%s", buf);//一般讲打印缓冲区而不打印指针
	}

	fclose(fp);
}


static void read_file_c() {
	FILE* fp = NULL;//野指针

	fp = fopen("C:\\Users\\Administrator\\Desktop\\ctest.txt", "r+");

	if (fp == NULL) {
		perror("打开文件失败 \n");//会打印错误信息
		return EXIT_FAILURE;
	}


#if WRITE_26_WORD_TO_FILE
	for (size_t i = 0; i < 26; i++)
	{
		fputc(97 + i, fp);//写入26个英文字符
	}
#endif // WRITE_26_WORD_TO_FILE

#if WRITE_END_TO_FILE

	char arr[] = { '0','c','a','b',-1,'d','e' };

	//printf("长度%d", sizeof(arr) / sizeof(char));

	for (int i = 0; i < sizeof(arr) / sizeof(char); i++) {
		fputc(arr[i], fp);
	}

#endif

	rewind(fp);//重置文件指针位置


	int f_getc_size;
	while ((f_getc_size = fgetc(fp)) != EOF) {
		printf("read c is %c \n", f_getc_size);
	}

	if (feof(fp)) {
		//fgetc返回的-1既有可能是读取到文件末尾也有可能是出错，使用feof判断是否真的读到了末尾
		printf("读取成功已到末尾");
	}
	else {
		printf("读取失败");
	}


	fclose(fp);//关闭文件
}

int main() {

#if mth_fgets_file
	fgets_file();
#endif // fgets

#if fputs_define

	write_fputs();
#endif 
#if fgets_put_file
	read_write();
#endif
#if file_operate_flag
	file_operate();
#endif
#if file_printf_test_flag
	file_printf();
#endif
#if file_scanf_test_flag
	file_scanf();
#endif

#if file_scanf_feof_test_flag
	file_scanf_feof();
#endif

#if file_scanf_out_of_range
	file_scanf_out_of_range_test();
#endif
#if file_random_sort
	file_random_sort_test();
#endif

#if file_write_flag
	file_write_test();
#endif
#if copy_big_file_flag
	big_file_copy();
#endif 
#if file_tell_flag
	file_tell_test();
#endif
#if file_read_after_write_flag
	file_write_after_read_test();
#endif
#if file_stat_flag
	file_stat_test();
#endif
}

static FILE* get_fp(const char* mode) {
	FILE* fp = NULL;

	fp = fopen(FILE_URL, mode);

	if (fp == NULL) {
		perror("获取文件失败");
		return NULL;
	}

	return fp;
}


static FILE* get_fp_url(const char* file, const char* mode) {
	return fopen(file, mode);
}

//fputs
static void write_fputs() {
	char buf[100] = "hello world";

	//向屏幕写入
	int res = fputs(buf, stdout);

	if (res > -1 && res != EOF) { //写入成功返回非负,如果发生错误返回EOF
		printf("写入成功");
	}

	printf("fputs result is %d", res);
}


static void read_write() {
	while (1) {
		char buf[100] = { 0 };

		char* read_res = fgets(buf, sizeof(buf), stdin);

		if (read_res == NULL) {
			perror("read fail");
			return;
		}

		FILE* fp = NULL;

		fp = fopen(FILE_URL, "a+");

		int put_res = fputs(buf, fp);

		fclose(fp);

		if (!strcmp(buf, ":wq\n")) {
			break;
		}
	}
}

static char* file_operate_to_file(Operate_s* operate_s) {
	char* str_concat_buf = malloc(100 * sizeof(char));
	if (str_concat_buf == NULL) {
		printf("error");
		return NULL;
	}

	sprintf(str_concat_buf, "%d%c%d=%d\n",
		operate_s->first_operate,
		operate_s->operate_flag,
		operate_s->second_operate,
		operate_s->operate_result);//sprintf:根据字符串格式化的内容从buffer取对应的值回填回变量
	return str_concat_buf;//返回指针必须要malloc
}

static void file_operate() {
	FILE* fp = NULL;

	FILE* write_fp = NULL;

	fp = fopen(FILE_URL, "r+");//定义读

	write_fp = fopen(FILE_URL, "a+");//定义写

	if (fp == NULL || write_fp == NULL) {
		printf("fopen fail");
		return;
	}

	char** all_line[100] = { 0 };//定义二级指针，写入的一句句话

	int line = 0;//不知道二级指针被写入了多少数据，只能用计数器，sizeof对指针取值固定
	while (1) {

		char buf[100] = { 0 };

		char* read_p = fgets(buf, 100, fp);

		if (read_p == NULL) {
			if (feof(fp)) {//是否读到文件末尾
				printf("read end \n");
			}
			if (ferror(fp)) {//是否读取出错
				printf("read error \n");
				clearerr(stdout);
			}
			break;
		}

		Operate_s operates = { 0 };//初始化结构体为默认值
		int ss_r = sscanf(
			buf,
			"%d%c%d=\n",
			&(operates.first_operate),
			&(operates.operate_flag),
			&(operates.second_operate)
		);//格式化字符串

		int operate_result = 0;

		char operate_result_str[100] = { 0 };

		switch (operates.operate_flag) {
		case ADD:
			operate_result = operates.first_operate + operates.second_operate;
			break;
		case SUBTRACT:
			operate_result = operates.first_operate - operates.second_operate;
			break;
		case MULTIPY:
			operate_result = operates.first_operate * operates.second_operate;
			break;
		case DIVIDE:
			operate_result = operates.first_operate / operates.second_operate;
			break;
		}

		operates.operate_result = operate_result;
		char* one_line = file_operate_to_file(&operates);//写入内容
		if (one_line == NULL) {
			return;
		}
		all_line[line] = one_line;//赋值二级指针，形成一句句话结构
		line++;
	}

	fclose(fp);

	for (size_t i = 0; i < line; i++) {
		fputs(all_line[i], write_fp);//写入文件
	}
	//释放
	for (size_t i = 0; i < line; i++) {
		free(all_line[i]);
	}
	fclose(write_fp);

}

static void file_printf() {
	FILE* fp = NULL;

	fp = fopen(FILE_URL, "a+");

	if (fp == NULL) {
		printf("fail to open file");
		return;
	}
	fprintf(fp, "%d%c%d=%d", 1, '+', 2, 1 + 2);

	fclose(fp);
}

static void file_scanf() {
	FILE* fp = get_fp("a+");
	if (fp == NULL) {
		return;
	}

	int one, two;

	char operate_f;

	int res;

	int scanf_res = fscanf(fp, "%d%c%d=%d", &one, &operate_f, &two, &res);

	printf("fscanf read result is %d%c%d=%d", one, operate_f, two, res);
}


static void file_scanf_feof() {
	//原文件1\n2\n3
	FILE* fp = get_fp("r");//读取文件
	if (fp == NULL) {
		return;
	}
	while (1) {
		int a;

		int res = fscanf(fp, "%d\n", &a);

		printf("read file before feof %d \n", a);

		if (feof(fp)) {
			printf("文件读取结束，退出循环");
			break;
		}
		//fscanf如果判断下次读取的format不符合则提前退出,因此后置打印会读取少数据
		printf("read file after feof %d \n", a);
	}

}

static void file_scanf_out_of_range_test() {
	//原文件1\n2\n3
	FILE* fp = get_fp("r");//读取文件
	if (fp == NULL) {
		return;
	}
	int a;
	int cou = 0;
	while (cou < 4) {

		int res = fscanf(fp, "%d\n", &a);

		printf("read file before feof %d \n", a);
		cou++;
	}
}


static void file_random_sort_test() {
	FILE* fp = get_fp("a+");//读取文件
	if (fp == NULL) {
		printf("fail to open file");
		return;
	}
	//写入文件随机数
	int arr[10] = { 3,2,1,5,2,6,1,3,21,2 };
	for (size_t i = 0; i < 10; i++) {
		char buf[100] = { 0 };
		/*sprintf(buf,"%d\n",arr[i]);
		fputs(buf, fp);*/
		fprintf(fp, "%d\n", arr[i]);//自带格式化,简化了sprintf+fputs
	}
	fclose(fp);//关闭写入文件操作

	FILE* write_fp = get_fp("r");//读文件

	if (write_fp == NULL) {
		printf("open w file error");
		return;
	}

	int cout = 0;

	int read_arr[10] = { 0 };

	while (1) {
		int a = 0;
		int r = fscanf(write_fp, "%d\n", &a);
		read_arr[cout] = a;
		cout++;
		if (feof(write_fp)) {
			break;
		}
	}
	for (size_t i = 0; i < 10; i++) { //选择排序
		int min_index = i;
		for (size_t n = i + 1; n < 10; n++) {
			if (read_arr[n] < read_arr[min_index]) {
				min_index = n;
			}
		}
		if (min_index != i) {
			int swap;

			swap = read_arr[i];

			read_arr[i] = read_arr[min_index];

			read_arr[min_index] = swap;
		}
	}

	for (size_t i = 0; i < 10; i++) {
		printf("%d\n", read_arr[i]);
	}

	fclose(write_fp);

	FILE* sort_finish_write_fp = get_fp("w");//写回文件

	if (sort_finish_write_fp == NULL) {
		return;
	}

	char write_str[1000] = { 0 };

	for (size_t i = 0; i < 10; i++) {
		fprintf(sort_finish_write_fp, "%d\n", read_arr[i]);
	}

	fclose(sort_finish_write_fp);
}


static void file_write_test() {
	FILE* fp = get_fp("wb");
	if (fp == NULL) {
		return;
	}
	FileWrite f = {
	1,"hello world",2
	};

	size_t write_res = fwrite(&f, sizeof(FileWrite), 1, fp);//写入一个结构体

	if (write_res == 0) {
		printf("write error");
		return;
	}

	fclose(fp);//调用close将写内容刷入文件

	FILE* read_fp = get_fp("rb");

	if (read_fp == NULL) {
		return;
	}
	FileWrite read_fw;

	size_t read_count = fread(&read_fw, sizeof(FileWrite), 1, read_fp);//读取一个结构体

	if (read_count == 0) {

		if (feof(read_fp)) {
			printf("正常情况，读到文件末尾\n");
		}
		else if (ferror(read_fp)) {
			perror("读取文件失败 \n");
			clearerr(read_fp);//清除错误原因
		}
		else {
			printf("请求读取的元素个数为0");
		}
		return;

	}

	printf("fread result is %d,%s,%d", read_fw.age, read_fw.name, read_fw.class);


	fclose(read_fp);
}


static void big_file_copy() {
	FILE* fp = get_fp_url(BIG_FILE_COPY_URL, "rb");
	FILE* write_fp = get_fp_url(BIG_FILE_COPY_DEST_URL, "wb");
	if (fp == NULL || write_fp == NULL) {
		perror("open file error\n");
		return;
	}
	char* buf = (char*)malloc(BIG_FILE_COPY_SIZE);//char buf[BIG_FILE_COPY_SIZE] = {0}不行，因为栈分配空间太小
	if (buf == NULL) {
		perror("malloc fail \n");

		return;
	}

	size_t read_bytes;

	//buf本身就是地址
	//每次fp读取1*BIG_FILE_COPY_SIZE大小的字节到buf中,并将实际读取的字节大小返回给read_bytes
	while ((read_bytes = fread(buf, 1, BIG_FILE_COPY_SIZE, fp)) > 0) {

		//从buf中取出1*read_bytes大小的字节写入到write_fp,取read_bytes是因为最后一次读取可能小于BIG_FILE_COPY_SIZE
		size_t write_bytes = fwrite(buf, 1, read_bytes, write_fp);
		if (write_bytes != read_bytes) {
			perror("write error \n");
			fclose(write_fp);
			free(buf);
			fclose(fp);
			return;
		}
	}

	if (ferror(write_fp)) {
		perror("write error \n");
		fclose(write_fp);
		fclose(fp);
		free(buf);
		return;
	}
}


static void file_tell_test() {
	FILE* fp = get_fp("rb");

	if (fp == NULL) {
		return;
	}

	int seek_res = fseek(fp, 0, SEEK_END);
	if (seek_res == -1) {
		perror("read error");
		return;
	}
	long size = ftell(fp);//文件大小(字节)

	printf("file size is %lu \n", size);

	//再回到文件开头
	rewind(fp);

	long rewind_size = ftell(fp);

	printf("rewind and get size %lu \n", rewind_size);

	fclose(fp);

}

static void file_write_after_read_test() {
	Operate_s op[4] = {
		{1,'a',1,2},
		{2,'b',3,4},
		{4,'c',3,3},
		{100,'d',3,3}
	};
	FILE* fp = get_fp("wb+");//可读可写
	size_t write_res =  fwrite(&op,sizeof(Operate_s), 4, fp);
	if (write_res == 0) {
		perror("write error \n");
		return;
	}
	
	printf("point position is %lu",ftell(fp));
	fseek(fp,0,SEEK_SET);
	
	while (1) {
		Operate_s op_read;
		size_t res =  fread(&op_read, sizeof(Operate_s),1, fp);
		printf("first is %zu",res);
		if (res == 0) {
			if (feof(fp)) {
				printf("read end of file \n");
			}
			else if (ferror(fp)) {
				perror("read error of file \n");
			}
			break;
		}
		printf("operate_s is %d,%c,%d,%d \n",
			op_read.first_operate,
			op_read.operate_flag,
			op_read.second_operate,
			op_read.operate_result);
	}
	
	fclose(fp);
}


static void file_stat_test() {
	struct stat buf;
	int ret = stat(FILE_URL,&buf);
	if (ret == 0) {
		
		printf("file size is %lu", buf.st_size);
	}
}
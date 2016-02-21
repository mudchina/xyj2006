//file		: baiban.c
//purpose	: 排版
//created	: 2002-2-8 1:52
//by			: take

//history	: 2002-2-8 1:52 take 创建文件

string dos2unix(string str);
string dropBlankLine(string str);
string combineLines(string str);
string split(string str, int lineLength);

int main(object me, string arg)
{
	string file, filePath, output;
	int lineLength;
	
	if( (sscanf(arg, "%s %d", filePath, lineLength)) != 2 ) {
		return notify_fail("指令格式为：baiban <filePath> <lineLength>\n");
	}
	
	file = read_file(filePath);
	file = dos2unix(file);
	file = dropBlankLine(file);
	file = combineLines(file);
	file = split(file, lineLength);
	write_file(filePath, file, 1);
	write(file + "\n");
	
	return 1;
}

string dos2unix(string str)
{
	string output, tmp;
	int i;
	
	output = "";
	tmp = " ";
	for( i=0; i<sizeof(str); i++) {
		if(str[i] == '\r') {
			continue;
		}
		tmp[0] = str[i];
		output = output + tmp;
	}	
	
	return output;
}

string dropBlankLine(string str)
{
	string output, *lines;
	int i, j;
	int isBlank;
	
	lines = explode(str, "\n");
	output = "";
	for( i=0; i<sizeof(lines); i++) {
		isBlank = 1;
		for( j=0; j<sizeof(lines[i]); j++) {
			if(lines[i][j] != ' ' && lines[i][j] != '	') {
				isBlank = 0;
			}
		}
		if(!isBlank) {
			output = output + lines[i];
		}
		output = output + "\n";
	}	
	
	return output;
}

string combineLines(string str)
{
	string output, tmp;
	int i;
	
	output = "";
	tmp = " ";
	for( i=0; i<sizeof(str); i++) {
		if((str[i] == '\n') &&
			 (i != 0 && str[i-1] != '\n') &&
			 (i != sizeof(str)-1 && str[i+1] != '\n') ) {
			continue;
		}
		tmp[0] = str[i];
		output = output + tmp;
	}	
	
	return output;
}

string split(string str, int lineLength)
{
	string output, tmp;
	int i, count, chCount;
	
	count = chCount = 0;
	output = "";
	tmp = " ";
	for( i=0; i<sizeof(str); i++) {
		if(str[i] > 127 || str[i] < 0) {
			chCount ++;
		}

		if(str[i] == '\n') {
			count = chCount = 0;
		}
		else {
			count ++;
		}
		
		if(count == lineLength && i != sizeof(str)-1 && str[i+1] != '\n') {
			if(chCount % 2) {
				i --;
			}	
			else {
				tmp[0] = str[i];
				output = output + tmp;
			}
			output = output + "\n";
			count = chCount = 0;
			continue;
		}

		tmp[0] = str[i];
		output = output + tmp;
	}
	
	return output;
}

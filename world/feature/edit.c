// edit.c

int edit(function callback)
{
	write("结束离开用 '.'，取消输入用 '~q'。\n"); // ，使用内建列编辑器用 '~e'。\n");
	write("————————————————————————————————————————\n");
	input_to("input_line", "", 0, callback);
	return 1;
}

#define MAXLINES 200
#define MAXCOL 80

void input_line(string line, string text, int lines, function callback)
{
        // mon 6/16/98
        line=CONVERT_D->input(line, this_object());

	if(strlen(line) > MAXCOL) {
		write("一行只能包含 "+MAXCOL+" 个字符，多余部分被忽略。\n");
		line = line[0..MAXCOL-1];
	}

	if( line=="." ) {
		(*callback)(text);
		return;
	} else if( line=="~q" ) {
		write("输入取消。\n");
		return;
//	} else if( line=="~e" ) {
	}

	if (lines >= MAXLINES) {
		write("正文超过 "+MAXLINES+" 行，多余部分被忽略。\n");
	} else {
		text += line + "\n";
		lines ++;
	}
	input_to("input_line", text, lines, callback);
}

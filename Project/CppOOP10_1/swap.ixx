export module swap;

export void swap(int&x, int&y)  // 노출시킬 것에만 export를 기입
{
	int temp = x;
	x = y;
	y = temp;
}
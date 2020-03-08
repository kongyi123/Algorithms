#define rint int
#define HASHSIZE 10007

int encode(char* paper, char* src, int papern) {
	int myhash[HASHSIZE] = {0,};
	long long table[1024] = {0,};
	for (int i = 0; i < HASHSIZE; ++i) myhash[i] = -1;
	int tlen[1024] = {0, };
	int cnt = 0;
	long long s = 0;
	int bit = 0;
	int all = 0;

	for (rint i = 0; i < papern; ++i) {
		s = 0;
		int len = 0;
		while (paper[i] && paper[i] != ' ') {
			s = (s << 5) + paper[i] - 'a' + 1;
			++i;
			++len;
		}
		rint key = s % HASHSIZE;
		while (myhash[key] != -1 && table[myhash[key]] != s) key = (key + 1) % HASHSIZE;
		if (myhash[key] == -1) {
			myhash[key] = cnt;
			tlen[cnt] = len;
			table[cnt++] = s;
		}
	}

	for (rint i = 0; i < cnt; ++i) {
		s = table[i];
		int len = tlen[i];
		int remain = 3;
		while (remain--) {
			src[(bit) / 8 + 2] |= (bool)(len & (1 << remain)) << ((bit) % 8);
			bit++;
		}

		remain = tlen[i] * 5;
		while (remain--) {
			src[bit / 8 + 2] |= (bool)(s & (1LL << remain)) << (bit % 8);
			bit++;
		}
	}

	bit += 3;

	for (rint i = 0; i < papern; ++i) {
		s = 0;
		while (paper[i] && paper[i] != ' ') {
			s = (s << 5) + paper[i] - 'a' + 1;
			++i;
		}
		int key = s % HASHSIZE;
		while (table[myhash[key]] != s) key = (key + 1) % HASHSIZE;
		int idx = myhash[key];
		int remain = 10;
		while (remain--) {
			src[bit / 8 + 2] |= (bool)(idx & (1 << remain)) << (bit % 8);
			bit++;
		}

		++all;
	}
	src[0] = all >> 8;
	src[1] = all & 0xff;

	return bit / 8 + 3;
}

void decode(char* src, char* dest, int s) {
	int alllen = ((int)src[0] << 8) + (unsigned char)src[1];
	long long str;
	int idx;
	long long table[1024];
	int tlen[1024];
	int bit = 0;
	int len;
	int rb;
	int tsize = 0;
	int di = 0;

	while (1) {
		len = 0;
		rb = 3;
		while (rb--) {
			len = (len << 1) + (src[bit / 8 + 2] & 1);
			src[bit++ / 8 + 2] >>= 1;
		}
		if (!len) break;
		tlen[tsize] = len;
		len *= 5;
		str = 0;
		while (len--) {
			str = (str << 1) + (src[bit / 8 + 2] & 1);
			src[bit++ / 8 + 2] >>= 1;
		}
		table[tsize++] = str;
	}

	for (rint i = 0; i < alllen; ++i) {
		rb = 10;
		idx = 0;
		while (rb--) {
			idx = (idx << 1) + (src[bit / 8 + 2] & 1);
			src[bit++ / 8 + 2] >>= 1;
		}
		str = table[idx];
		for (int i = 0; i < tlen[idx]; ++i) {
			dest[di + i] = (str & 0x1f) + 'a' - 1;
			str >>= 5;
		}
		for (int i = 0; i < tlen[idx] / 2; ++i) {
			char t = dest[di + i];
			dest[di + i] = dest[di + tlen[idx] - 1 - i];
			dest[di + tlen[idx] - 1 - i] = t;
		}
		dest[di + tlen[idx]] = ' ';
		di += tlen[idx] + 1;
	}
	for (int i = 0; i < s; ++i) src[i] = 0;
}
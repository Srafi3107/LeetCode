int strStr(string haystack, string needle) {
    size_t index = haystack.find(needle);
    return (index != string::npos) ? index : -1;
}

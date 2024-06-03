class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        paragraph = Paragraph(words, maxWidth)
        print(paragraph)

class Paragraph():

    def __init__(self, words, max_line_width) -> None:
        self.max_line_width = max_line_width
        self.lines = list()

        while(len(words)):
            line = Line(max_line_width)
            line.fill(words)
            self.lines.append(line)
    
    def __str__(self) -> str:
        string = ""

        for line in self.lines:
            string += str(line)
        
        return string



class Line():

    def __init__(self, max_width) -> None:
        self.start = ""
        self.end = ""
        self.__str__ = ""
        self.max_width = max_width
        self.last_line = False
        self.words = list()

    def __str__(self) -> str:

        string = ""
        if (not self.last_line):
            string = "Not last\n"
        else:
            string = "Last\n"
        return string

    def fill(self, total_words):
        index = 0
        word_chars_count = 0
        #index+=1

        for word in total_words:

            # If line length after adding this word and spaces is less than or equal max_width.
            if (word_chars_count + index + len(word) <= self.max_width):
                self.words.append(word)
                word_chars_count += len(total_words[index])
                index += 1
            else:
                break
        
        for i in range(index-1, -1, -1):
            total_words.pop(i)

        
        # If no more words, then this is the last line.
        if(not len(total_words)):
            self.last_line = True

        
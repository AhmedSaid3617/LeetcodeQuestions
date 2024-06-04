class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        paragraph = Paragraph(words, maxWidth)
        paragraph.print_lines()
        return paragraph.get_lines_strings()

class Paragraph():

    def __init__(self, words, max_line_width) -> None:

        self.max_line_width = max_line_width
        self.words = words
        self.lines = []

        while(len(words)):
            line = Line(max_line_width)
            line.fill(words)
            self.lines.append(str(line))
    
    def __str__(self) -> str:
        string = ""

        for line in self.lines:
            string += str(line)
        
        return string
    
    def print_lines(self):
        print(self.lines)

    def get_lines_strings(self):
        lines_strings = []
        for line in self.lines:
            lines_strings.append(str(line))
        return lines_strings



class Line():

    def __init__(self, max_width) -> None:
        self.max_width = max_width
        self.last_line = False
        self.words = []

    def __str__(self) -> str:

        string = ""

        # Add one space between words.
        for i in range(len(self.words) -1):
            self.words[i] += " "
        
        min_length = sum(len(word) for word in self.words)
        spaces_count = self.max_width - min_length
            
        
        if not self.last_line:
            while spaces_count:
                self.words[0] += " "
                spaces_count -= 1

                j = 1
                while j < len(self.words) -1 and spaces_count:
                    self.words[j] += " "
                    spaces_count -=1
                    j += 1
        
        else:
            for i in range(spaces_count):
                self.words[-1] += " "

        for word in self.words:
            string += word

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

        
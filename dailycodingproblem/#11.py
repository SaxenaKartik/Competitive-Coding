""" Making a trie of the dictionary of words
	
	Example : 
		>>> python3 #11.py
		apple mango man beer ma
		ma
		['man', 'mango']

"""

class Trie:
	"""Class to make a new trie 
		
		Example : 
		>>> obj = Trie()
		>>> obj.root
		{'#':False}

	"""
	def __init__(self):
		""" Initialise function to make a new trie node

			Attributes:
				root (dict): Root node of the trie of dictionary of words
				
		"""
		self.root = {'#': False}

	def make_trie(self, dictionary: list):
		""" Makes the trie out of a dictionary of words
			
			Example: 
				>>> obj.make_trie(['app'])
				{'#':False, 'a': {'#': False, 'p':{ '#': False, 'p': {'#': True}}}}

			Args:
				dictionary (list[str]): The dictionary of words that are given as input

		"""
		for word in dictionary:
			node = self.root
			for index,letter in enumerate(word):
				if letter in node:
					if index==len(word)-1:
						node['#'] = True
					else:
						node = node[letter]
				else:
					if index==len(word)-1:
						node[letter] = {'#': True}
					else:
						node[letter] = {"#": False}
						node = node[letter]
		# print(self.root)

	def starts_with(self, s:str)->list:
		""" Returns the list of words that start with s
				
			Example:
				Say given dictionary of words be ['apple', 'apples', 'app'] 
				>>>obj.starts_with('appl')
				['apple', 'apples']

			Args:
				s (str): The prefix given in the question

			Returns: 
				node (Trie): Trie node which points to the words that start with s
				ans (list[str]): List of words that start with s 

		"""
		ans = []
		node = self.root
		for index,letter in enumerate(s):
			if letter in node:
				node = node[letter]
			else:
				return []
		# print(node)


		def dfs(node, path):
			"""
				Args: 
					node (Trie): Used to recursively find the required words one letter at a time
					path (str): Used to string up the required words with letters

				Returns:
					None

				Note: 
					It appends the required words to the ans list
					
			"""

			if node['#']==True:
				ans.append(path)

			for letter in node:
				s = path
				if letter != '#':
					s += letter
					dfs(node[letter], s)


		dfs(node, s)
		return ans

if __name__ == "__main__":
	

	dictionary = input().split()
	string = input()

	obj = Trie()
	obj.make_trie(dictionary)
	print(obj.starts_with(string))
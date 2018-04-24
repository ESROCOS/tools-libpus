class Table(list):
    """
    This class override the list class to be able
    to implement events when an element is added
    """
    def __init__(self):
        self.onChange = None
        self.onClear = None
        super().__init__()

    def __getitem__(self, key):
        return super().__getitem__(key)

    def __setitem__(self, key, value):
        self.onChange(key, value)
        super().__setitem__(key, value)

    def append(self, item):
        self.onChange(super().__len__(), item)
        super().append(item)

    def clear(self):
        self.onClear()
        super().clear()

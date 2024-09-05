class Contact {
    constructor(name, number, email) {
        this.name = name;
        this.number = number;
        this.email = email;
    }
}

class PhoneBook {
    constructor() {
        this.contacts = JSON.parse(localStorage.getItem('contacts')) || [];
    }

    addContact(contact) {
        this.contacts.push(contact);
        this.sortContacts();
        this.saveContacts();
    }

    deleteContact(index) {
        this.contacts.splice(index, 1);
        this.saveContacts();
    }

    sortContacts() {
        this.contacts.sort((a, b) => a.name.localeCompare(b.name));
    }

    saveContacts() {
        localStorage.setItem('contacts', JSON.stringify(this.contacts));
    }

    searchContacts(query) {
        return this.contacts.filter(contact => 
            contact.name.toLowerCase().includes(query.toLowerCase()) ||
            contact.number.includes(query) ||
            contact.email.toLowerCase().includes(query.toLowerCase())
        );
    }
}

const phoneBook = new PhoneBook();
const contactForm = document.getElementById('contactForm');
const contactList = document.getElementById('contactList');
const searchInput = document.getElementById('searchInput');
const searchResults = document.getElementById('searchResults');

contactForm.addEventListener('submit', (e) => {
    e.preventDefault();
    const name = document.getElementById('name').value;
    const number = document.getElementById('number').value;
    const email = document.getElementById('email').value;

    const newContact = new Contact(name, number, email);
    phoneBook.addContact(newContact);
    updateContactList();
    contactForm.reset();
});

function updateContactList() {
    contactList.innerHTML = '';
    phoneBook.contacts.forEach((contact, index) => {
        const li = createContactElement(contact, index);
        contactList.appendChild(li);
    });
}

function createContactElement(contact, index) {
    const li = document.createElement('li');
    li.className = 'contact';
    li.innerHTML = `
        <strong>${contact.name}</strong><br>
        Phone: ${contact.number}<br>
        Email: ${contact.email}
        <button onclick="deleteContact(${index})">Delete</button>
    `;
    return li;
}

function deleteContact(index) {
    phoneBook.deleteContact(index);
    updateContactList();
}

searchInput.addEventListener('input', (e) => {
    const query = e.target.value;
    const results = phoneBook.searchContacts(query);
    displaySearchResults(results);
});

function displaySearchResults(results) {
    searchResults.innerHTML = '';
    results.forEach(contact => {
        const li = createContactElement(contact);
        searchResults.appendChild(li);
    });
}

// Tab functionality
const tabButtons = document.querySelectorAll('.tab-button');
const tabContents = document.querySelectorAll('.tab-content');

tabButtons.forEach(button => {
    button.addEventListener('click', () => {
        const tabName = button.getAttribute('data-tab');
        
        tabButtons.forEach(btn => btn.classList.remove('active'));
        tabContents.forEach(content => content.classList.remove('active'));
        
        button.classList.add('active');
        document.getElementById(tabName).classList.add('active');
    });
});

// Initial load
updateContactList();
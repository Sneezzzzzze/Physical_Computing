setTimeout(function () {
    var loadingDiv = document.getElementById("loading");
    var wrapDiv = document.getElementById("wrap");
    loadingDiv.style.display = "none";
    wrapDiv.style.display = "block";
}, 2000);

document.addEventListener("DOMContentLoaded", function () {
    // Get the modal
    var modal = document.getElementById("myModal");
    // Get the button that opens the modal
    var btn = document.getElementById("modalBtn");
    // Get the <span> element that closes the modal
    var span = document.getElementsByClassName("close")[0];
  
    // When the user clicks on the button, open the modal
    btn.onclick = function() {
      modal.style.display = "block";
    };
  
    // When the user clicks on <span> (x), close the modal
    span.onclick = function() {
      modal.style.display = "none";
    };
  
    // When the user clicks anywhere outside of the modal, close it
    window.onclick = function(event) {
      if (event.target == modal) {
        modal.style.display = "none";
      }
    };
    const cmdInput = document.getElementById('cmd-input');
    const output = document.getElementById('output');

    cmdInput.addEventListener('keydown', function (event) {
        if (event.key === "Enter") {
            event.preventDefault();
            const command = cmdInput.value;
            cmdInput.value = "";
            output.innerHTML += `<div>> ${command}</div>`;
            handleCommand(command);
        }
    });

    function handleCommand(command) {
        if (command === 'help' || command === '-h') {
            output.innerHTML += `<div>Available commands:</div>
                                <div>- -h help: Display available commands</div>
                                <div>- -o open: Open 'ProjectC.cpp' file</div>
                                <div>- -c clear: Clear the command prompt</div>`;
        } else if (command === 'clear' || command === '-c') {
            output.innerHTML = "";
        } else if (command.startsWith('open') || command.startsWith('-o')){
            openCFile('ProjectC.cpp');
        } else {
            output.innerHTML += `<div>Command not found: ${command}</div>`;
        }
    }

    function openCFile(fileName) {
        fetch(fileName)
            .then(response => response.text())
            .then(content => {
                const pre = document.createElement('pre');
                pre.textContent = content;
                pre.style.color = '#008184';
                output.appendChild(pre);
            })
            .catch(error => {
                output.innerHTML += `<div>Error loading file: ${error}</div>`;
            });
    }
  });

  document.addEventListener('DOMContentLoaded', function () {
    const content = document.querySelector('.content');
    const footer = document.querySelector('.footer');
    
    content.addEventListener('scroll', () => {
        if (content.scrollTop + content.clientHeight >= content.scrollHeight) {
            // User has scrolled to the bottom
            footer.style.display = 'flex';
        } else {
            // User is not at the bottom
            footer.style.display = 'none';
        }
    });
});

let checkedCount = 0;
const checkboxes = document.querySelectorAll('.task-checkbox');
const progress = document.querySelector('.progress');
const text = document.querySelector('.text');

checkboxes.forEach(checkbox => {
    checkbox.addEventListener('change', () => {
        if (checkbox.checked) {
            checkedCount++;
        } else {
            checkedCount--;
        }
        updateProgress();
    });
});

function updateProgress() {
    const percent = (checkedCount / checkboxes.length) * 100;
    progress.style.width = percent + '%';
    text.innerHTML = `<p>${Math.round(percent)}%</p>`;
}

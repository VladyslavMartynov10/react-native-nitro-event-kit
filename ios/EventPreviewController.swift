import UIKit
import EventKit

class EventPreviewController: UIViewController {
    private let eventIdentifier: String
    private var event: EKEvent?
    
    private let scrollView = UIScrollView()
    private let contentView = UIView()
    private let stackView = UIStackView()
    
    private let titleLabel = EventDetailLabel(text: "", font: .boldSystemFont(ofSize: 22), textColor: .label)
    private let dateLabel = EventDetailLabel(text: "", numberOfLines: 2)
    
    init(eventIdentifier: String) {
        self.eventIdentifier = eventIdentifier
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .systemBackground
        setupNavigationBar()
        setupScrollView()
        fetchEvent()
    }
    
    private func setupNavigationBar() {
        title = "Event Details"
        navigationItem.rightBarButtonItem = UIBarButtonItem(customView: CloseButton(title: "Done", target: self, action: #selector(dismissController)))
    }
    
    @objc private func dismissController() {
        dismiss(animated: true)
    }
    
    private func setupScrollView() {
        scrollView.translatesAutoresizingMaskIntoConstraints = false
        contentView.translatesAutoresizingMaskIntoConstraints = false
        stackView.translatesAutoresizingMaskIntoConstraints = false
        
        view.addSubview(scrollView)
        scrollView.addSubview(contentView)
        contentView.addSubview(stackView)
        
        NSLayoutConstraint.activate([
            scrollView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor),
            scrollView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            scrollView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            scrollView.bottomAnchor.constraint(equalTo: view.bottomAnchor),
            
            contentView.topAnchor.constraint(equalTo: scrollView.topAnchor),
            contentView.leadingAnchor.constraint(equalTo: scrollView.leadingAnchor),
            contentView.trailingAnchor.constraint(equalTo: scrollView.trailingAnchor),
            contentView.bottomAnchor.constraint(equalTo: scrollView.bottomAnchor),
            contentView.widthAnchor.constraint(equalTo: scrollView.widthAnchor),
            
            stackView.topAnchor.constraint(equalTo: contentView.topAnchor, constant: 20),
            stackView.leadingAnchor.constraint(equalTo: contentView.leadingAnchor, constant: 16),
            stackView.trailingAnchor.constraint(equalTo: contentView.trailingAnchor, constant: -16),
            stackView.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -20)
        ])
        
        stackView.axis = .vertical
        stackView.spacing = 10
    }
    
    private func setupEventDetails(event: EKEvent) {
        titleLabel.text = event.title
        dateLabel.text = event.startDate.eventFormattedText(to: event.endDate)
        
        let calendarInfoView = PreviewCalendarInfoView(title: event.calendar.title, color: event.calendar.cgColor)

        let alertView = createRow(title: "Alert", value: "10 minutes before")
        let secondAlertView = createRow(title: "Second Alert", value: "None")
        let notesView = createNotesView(text: event.notes ?? "No additional notes")

        
        stackView.addArrangedSubview(titleLabel)
        stackView.addArrangedSubview(dateLabel)
        stackView.addArrangedSubview(addSectionView(calendarInfoView))
        stackView.addArrangedSubview(addSectionView(alertView))
        stackView.addArrangedSubview(addSectionView(secondAlertView))
        stackView.addArrangedSubview(addSectionView(notesView))
    }
    
    private func fetchEvent() {
        guard let fetchedEvent = EventKitManager.shared.eventStore.event(withIdentifier: self.eventIdentifier) else {
            DispatchQueue.main.async { self.dismiss(animated: true) }
            return
        }
        
        self.event = fetchedEvent
        DispatchQueue.main.async { self.setupEventDetails(event: fetchedEvent) }
    }
    
    private func createRow(title: String, value: String) -> UIView {
        let label = EventDetailLabel(text: title, font: .systemFont(ofSize: 16, weight: .medium), textColor: .label)
        let valueLabel = EventDetailLabel(text: value, textColor: .gray)

        let container = UIView()
        let stack = UIStackView(arrangedSubviews: [label, valueLabel])
        stack.axis = .horizontal
        stack.distribution = .equalSpacing
        stack.alignment = .center
        stack.translatesAutoresizingMaskIntoConstraints = false
        
        container.addSubview(stack)
        NSLayoutConstraint.activate([
            stack.leadingAnchor.constraint(equalTo: container.leadingAnchor, constant: 16),
            stack.trailingAnchor.constraint(equalTo: container.trailingAnchor, constant: -16),
            stack.topAnchor.constraint(equalTo: container.topAnchor, constant: 10),
            stack.bottomAnchor.constraint(equalTo: container.bottomAnchor, constant: -10)
        ])
        
        return container
    }
    
    private func createNotesView(text: String) -> UIView {
        let titleLabel = EventDetailLabel(text: "Notes", font: .systemFont(ofSize: 16, weight: .medium), textColor: .label)
        
        let notesTextView = UITextView()
        notesTextView.text = text
        notesTextView.font = UIFont.systemFont(ofSize: 16)
        notesTextView.textColor = .gray
        notesTextView.isEditable = false
        notesTextView.isScrollEnabled = false
        notesTextView.backgroundColor = .clear
        notesTextView.translatesAutoresizingMaskIntoConstraints = false
        
        let container = UIView()
        let stack = UIStackView(arrangedSubviews: [titleLabel, notesTextView])
        stack.axis = .vertical
        stack.spacing = 6
        stack.translatesAutoresizingMaskIntoConstraints = false
        
        container.addSubview(stack)
        NSLayoutConstraint.activate([
            stack.leadingAnchor.constraint(equalTo: container.leadingAnchor, constant: 16),
            stack.trailingAnchor.constraint(equalTo: container.trailingAnchor, constant: -16),
            stack.topAnchor.constraint(equalTo: container.topAnchor, constant: 10),
            stack.bottomAnchor.constraint(equalTo: container.bottomAnchor, constant: -10)
        ])
        
        return container
    }
    
    private func addSectionView(_ view: UIView) -> UIView {
        let container = UIView()
        container.backgroundColor = .secondarySystemBackground
        container.layer.cornerRadius = 8
        container.addSubview(view)
        view.translatesAutoresizingMaskIntoConstraints = false
        
        NSLayoutConstraint.activate([
            view.leadingAnchor.constraint(equalTo: container.leadingAnchor),
            view.trailingAnchor.constraint(equalTo: container.trailingAnchor),
            view.topAnchor.constraint(equalTo: container.topAnchor),
            view.bottomAnchor.constraint(equalTo: container.bottomAnchor),
            container.heightAnchor.constraint(greaterThanOrEqualToConstant: 44)
        ])
        
        return container
    }
}
